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

#ifndef _SFEX_NUMERIC_GRADIENT_HPP_
#define _SFEX_NUMERIC_GRADIENT_HPP_

#include <map>
#include <SFEX/Numeric/Math.hpp>

namespace sfex
{

/// @brief A gradient class that allows you to create gradients between anything that supports addition and multiplication operators.
template<typename T>
class Gradient
{
public:

/// @brief Adds time,key pair to map.
void setKey(float time, const T& key);

/// @brief Removes a key by value
/// @param val the key you want to remove
void removeKey(const T& val);

/// @brief Removes a key by time
void removeKey(float time);

/// @brief Returns all time and key pairs as a map
/// @return Time and key pairs
std::map<float, T> getKeys();

/// @brief Calculates a key based on given time value
/// @param time time value
/// @return key corresponding to that time value
T evaluate(float time);

private:
std::map<float, T> m_keys;
};

} // namespace sfex

#include <SFEX/Numeric/Gradient.inl>

#endif // !_SFEX_NUMERIC_GRADIENT_HPP_