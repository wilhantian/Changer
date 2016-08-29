#include "SpriteSystem.h"
#include "Game/Component/ComDefine.h"

void SpriteSystem::tick(double fixedDelta)
{
	auto all = Entity::getAll<SpriteCom>();
    for(Eid id : all)
    {
        Ent ent = Ent(id);
        SpriteCom sprite = ent.sprite;
		PositionCom position = ent.position;

		if (!sprite.bitmap)//not init
		{
			sprite.bitmap = al_load_bitmap(sprite.filename.c_str());
		}

		if (sprite.spriteType == SpriteType::Static)
		{
			int x = position.x;
			int y = position.y;
			int sourceX = 0;
			int sourceY = 0;
			int sourceW = al_get_bitmap_width(sprite.bitmap);
			int sourceH = al_get_bitmap_height(sprite.bitmap);
			int centerX = 0;
			int centerY = 0;

			al_draw_tinted_scaled_rotated_bitmap_region(
				sprite.bitmap,
				sourceX, sourceY, sourceW, sourceH,
				al_map_rgb(0.5, 0.5, 0.5),
				centerX, centerY,
				x, y,
				1, 1,
				0, 1
			);
		}
		else if (sprite.spriteType == SpriteType::Anime)
		{
			int col = sprite.frameCol;

			int x = position.x;
			int y = position.y;
			int sourceX = (sprite.frameWidth / col) * (sprite.curFrame % col);
			int sourceY = (sprite.frameHeight) * (sprite.curFrame / col);
			int sourceW = sprite.frameWidth;
			int sourceH = sprite.frameHeight;
			int centerX = 0;
			int centerY = 0;

			al_draw_bitmap_region(sprite.bitmap, sourceX, sourceY, sourceW, sourceH, x, y, 1);

// 			al_draw_tinted_scaled_rotated_bitmap_region(
// 				sprite.bitmap,
// 				sourceX, sourceY, sourceW, sourceH,
// 				al_map_rgb(.5, .5, .5),
// 				centerX, centerY,
// 				x, y, 
// 				1, 1, 
// 				0, 0
// 			);
		}
    }
}