#pragma once

#include "cjUI.h"

namespace cj {

	class SfmlSprite : public Sprite
	{
	protected:
		sf::Sprite *sprite;
	public:
		SfmlSprite(Control *owner);
		virtual ~SfmlSprite();

		sf::Sprite* getSfSprite();

		void setTexture(Texture &tx);
		void setTextureRect(Rect rect);
		void setPosition(int x, int y);

	};

}