//#include "Player.h"
//
//
//
//Player::Player(const char* texturesheet, int x, int y): GameObject(texturesheet, x, y)
//{
//	
//}
//
//
//Player::~Player(){}
//
//void Player::UpdatePlayer1()
//{
//	{
//		if (alive) {
//
//			xOld = xpos;
//			yOld = ypos;
//
//			speed = physics->SpeedIncrease();
//			//elo = physics->CheckCollision(destRect, kol);
//
//			auto kstate = SDL_GetKeyboardState(NULL);
//			if (jump == false) {
//
//				if (kstate[SDL_SCANCODE_LEFT])
//					xpos -= (1.0 + speed);
//				if (kstate[SDL_SCANCODE_RIGHT] /*&& !elo*/)
//					xpos += (1.0 + speed);
//				if (kstate[SDL_SCANCODE_UP] /*&& !elo*/) {
//
//					jump = true;
//					yposBeforeJump = ypos;
//					ypos -= (44.0) + speed;
//				}
//				if (kstate[SDL_SCANCODE_RCTRL])
//					speed = physics->SpeedDecrease();
//				if (kstate[SDL_SCANCODE_DOWN] && !elo) {
//					ypos += 1.0;
//
//				}
//
//			}
//			else if (jump)
//			{
//
//				if (kstate[SDL_SCANCODE_LEFT] && !elo)
//					xpos -= (1.0 + speed * 1.4);
//				if (kstate[SDL_SCANCODE_RIGHT] && !elo)
//					xpos += (1.0 + speed * 1.4);
//
//				if (ypos >= yposBeforeJump) {
//					jump = false;
//
//				}
//				else
//					ypos += 1.0;
//
//			}
//
//			collider.x = xOld;
//			collider.y = yOld;
//			collider.h = 32;
//			collider.w = 32;
//
//			for (auto& i : collidingRects)
//			{
//
//
//				elo = physics->CheckCollision(collider, i);
//				if (elo)
//				{
//					break;
//				}
//			}
//
//			if (elo)
//			{
//				///speed = 0;
//				destRect.x = xOld;
//				destRect.y = yOld;
//			}
//			else
//			{
//				destRect.x = xpos;
//				destRect.y = ypos;
//			}
//
//			srcRect.h = 32;
//			srcRect.w = 32;
//			srcRect.x = 0;
//			srcRect.y = 0;
//
//
//			destRect.w = srcRect.w * 2;
//			destRect.h = srcRect.h * 2;
//
//
//
//
//
//
//
//
//
//
//
//
//
//			destRect = physics->keepInFrames(destRect, xpos, ypos);
//		}
//
