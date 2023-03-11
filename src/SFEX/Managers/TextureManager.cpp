// MIT License

// Copyright (c) 2023 Yunus Emre Aydın

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <SFEX/Managers/TextureManager.hpp>

namespace sfex
{

bool TextureManager::hasTexture(const std::string &key) const
{
    return (m_textures.find(key) != m_textures.end());
}

std::size_t TextureManager::size() const
{
    return m_textures.size();
}

bool TextureManager::create(const std::string &key, unsigned int width, unsigned int height)
{
    sf::Texture fooTexture;

    bool result = fooTexture.create(width, height);
    if(!result) return false;

    m_textures[key] = std::move(fooTexture);
    return true;
}

bool TextureManager::loadFromFile(const std::string &key, const std::string &filename, const sf::IntRect &area)
{
    sf::Texture fooTexture;

    bool result = fooTexture.loadFromFile(filename, area);
    if(!result) return false;

    m_textures[key] = std::move(fooTexture);
    return true;
}

bool TextureManager::loadFromMemory(const std::string &key, const void *data, std::size_t size, const sf::IntRect &area)
{
    sf::Texture fooTexture;

    bool result = fooTexture.loadFromMemory(data, size);
    if(!result) return false;

    m_textures[key] = std::move(fooTexture);
    return true;
}

bool TextureManager::loadFromStream(const std::string &key, sf::InputStream &stream, const sf::IntRect &area)
{
    sf::Texture fooTexture;

    bool result = fooTexture.loadFromStream(stream, area);
    if(!result) return false;

    m_textures[key] = std::move(fooTexture);
    return true;
}

bool TextureManager::loadFromImage(const std::string &key, const sf::Image &image, const sf::IntRect &area)
{
    sf::Texture fooTexture;

    bool result = fooTexture.loadFromImage(image, area);
    if(!result) return false;

    m_textures[key] = std::move(fooTexture);
    return true;
}

sf::Texture* TextureManager::get(const std::string &key)
{
    if(!hasTexture(key)) return nullptr;
    return &m_textures[key];
}

std::vector<std::string> TextureManager::getKeys() const
{
    std::vector<std::string> result;
    for(auto &p : m_textures)
    {
        result.push_back(p.first);
    }
    return result;
}

sf::Texture* TextureManager::operator[](const std::string& key)
{
    return get(key);
}

} // namespace sfex
