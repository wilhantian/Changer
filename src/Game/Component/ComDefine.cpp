#include "ComDefine.h"

#define DEFINE_COM(_CLASS_NAME_)  Cid _CLASS_NAME_::cid = __id++;
#define DEFINE_COM_BEGIN static unsigned __id = 0;
#define DEFINE_COM_END Cid Entity::Component::numCids = __id; 

#define REGISTER_COM(_CLASS_NAME_, _PARAM_NAME_) _PARAM_NAME_(Entity::get<_CLASS_NAME_>(_id)),
#define REGISTER_COM_BEGIN System::Ent::Ent(Eid _id):
#define REGISTER_COM_ENG id(_id){}

/// 定义组件
DEFINE_COM_BEGIN
DEFINE_COM(SpriteCom)
DEFINE_COM(PositionCom)
DEFINE_COM(PhysicsCom)
DEFINE_COM(BodyCom)
DEFINE_COM_END

/// 注册组件
REGISTER_COM_BEGIN
REGISTER_COM(SpriteCom, sprite)
REGISTER_COM(PositionCom, position)
REGISTER_COM(PhysicsCom, physics)
REGISTER_COM(BodyCom, body)
REGISTER_COM_ENG