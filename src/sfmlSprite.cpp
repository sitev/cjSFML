#include "cj.h"
#include "cjUI.h"
#include "cjSFML.h"

namespace cj {

	SfmlSprite::SfmlSprite(Control *owner) : Sprite(owner) {
		sprite = new sf::Sprite();
	}


	SfmlSprite::~SfmlSprite() {
		delete sprite;
	}

	sf::Sprite* SfmlSprite::getSfSprite() {
		return sprite;
	}

	void SfmlSprite::setTexture(Texture &tx) {
		this->tx = &tx;

		SfmlTexture* sfmlTexture = (SfmlTexture*)&tx;
		sf::Texture *sfTexture = sfmlTexture->getSfTexture();
		sprite->setTexture(*sfTexture);

		sf::Vector2u sz = sfTexture->getSize();
		setW(sz.x);
		setH(sz.y);
	}

	void SfmlSprite::setTextureRect(Rect r) {
		sf::IntRect rect;
		rect.left = r.pos.x;
		rect.top = r.pos.y;
		rect.width = r.size.w;
		rect.height = r.size.h;

		sprite->setTextureRect(rect);

		sf::Vector2u sz = sprite->getTexture()->getSize();
		setW(sz.x);
		setH(sz.y);
	}

	void SfmlSprite::setPosition(int x, int y) {
		sprite->setPosition(x, y);
	}

	void SfmlSprite::setFrame(String value) {
		Sprite::setFrame(value);

		Rect r(sf->x, sf->y, sf->w, sf->h, true);
		setTextureRect(r);
	}


}