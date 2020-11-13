#include "pch.h"
#include "Texture.h"
#include "Renderer.h"

namespace nc
{
	bool nc::Texture::Create(const std::string& name, void* renderer)
	{
		m_renderer = static_cast<Renderer*>(renderer)->m_renderer;

		SDL_Surface* surface = nullptr; // IMG_Load(name.c_str());
		if (surface == nullptr)
		{
			return false;
		}

		m_texture = SDL_CreateTextureFromSurface(m_renderer, surface);
		SDL_FreeSurface(surface);

		if (m_texture == nullptr)
		{
			return false;
		}

		return true;
	}

	void nc::Texture::Destroy()
	{
		SDL_DestroyTexture(m_texture);
	}
}