#include "SpriteSystem.h"
#include "Game/Component/ComDefine.h"

void SpriteSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<SpriteCom>();
    for(Eid id : all)
    {
        Ent ent = Ent(id);
        SpriteCom sprite = ent.sprite;
        
        // if frames size=0, that the sprite is not init
        if(sprite.frames.size() == 0)
        {
            
        }
    }
}