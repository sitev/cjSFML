#pragma once

namespace cj {

	class SfmlTexture : public Texture {
	protected:
		sf::Texture *texture;
	public:
		SfmlTexture();
		~SfmlTexture();

		virtual bool loadFromFile(String fileName);

		virtual sf::Texture *getSfTexture();
	};

}