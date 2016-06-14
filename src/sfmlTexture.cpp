#include "cj.h"
#include "cjUI.h"
#include "cjSFML.h"

namespace cj {

	SfmlTexture::SfmlTexture() {
		texture = new sf::Texture();
	}

	SfmlTexture::~SfmlTexture() {
		delete texture;
	}

	bool SfmlTexture::loadFromFile(String fileName) {
		return texture->loadFromFile(fileName.to_string());
	}

	sf::Texture *SfmlTexture::getSfTexture() {
		return texture;
	}

}