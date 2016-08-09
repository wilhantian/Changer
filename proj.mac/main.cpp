#include <allegro5/allegro.h>
#include "Framework/ECS/EntityFu.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#define _sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define _sleep(ms) usleep(ms * 1000)
#endif

#define ENTITY_REGIST_COMPONENT(componentClass) a


using namespace std;

// 血量组件
struct HealthComponent : Entity::Component
{
    int hp, maxHP;
    
    HealthComponent(int _hp, int _maxHP)
    {
        hp = _hp;
        maxHP = _maxHP;
    }
    
    HealthComponent() : HealthComponent(0, 0) {}
    
    virtual bool empty() const {return maxHP == 0;}
    
    static Cid cid;
};

/// 指定唯一的ID
static Cid _id = 0;
Cid HealthComponent::cid = _id++;
Cid Entity::Component::numCids = _id;

/// 系统容器
struct System::Ent
{
    Eid id;
    HealthComponent& health;
    /// 这里添加其他组件
    
    Ent(Eid _id) :
    health(Entity::get<HealthComponent>(_id)),
    id(_id)
    {}
};

/// 生命系统
struct HealthSystem : System
{
    static void tick(double fixedDelta)
    {
        auto all = Entity::getAll<HealthComponent>();
        
        for (auto eid : all)
        {
            Ent e(eid);
            
            // 这个代码过于务实, 不过你可以检查你的组件是否有效
            if (e.health.empty())
                continue;
            
            // 减血
            e.health.hp--;
            if (e.health.hp < 0)
                e.health.hp = 0;
            cout << "Entity " << (int)e.id << " has " << e.health.hp << "/" << e.health.maxHP << " hit points." << endl;
            
            // 如果血量为零, 这销毁这个实体
            if (e.health.hp <= 0)
                Entity::destroyNow(eid);
        }
    }
};

int main(int argc, char **argv)
{
    Entity::create(new HealthComponent(100, 100));
    Entity::create(new HealthComponent(7, 7));
    
    while (Entity::count())
    {
        HealthSystem::tick(0.1);
        _sleep(100);
    }
    
    Entity::dealloc();
    cout << "Goodbye, World!\n";
    return 0;
}
