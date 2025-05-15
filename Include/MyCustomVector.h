// Copyright (c) Entropy Software LLC
// This file is licensed under the MIT License.
// See the LICENSE file in the project root for more information.

// Dummy Vector class to show how the default vector type can be changed

#pragma once

#include <vector>

namespace MyNamespace
{

template <typename T>
class MyVector
{
public:
    int GetCount() const { return (int)_v.size(); }

    inline const T& At(int index) const { return _v[index]; }

    inline void Add(const T& value) { _v.push_back(value); }
    inline void Add(T&& value) { _v.push_back(std::move(value)); }

private:
    std::vector<T> _v;
};

} // namespace MyNamespace

// VectorOps must be in the Entropy namespace and have this exact interface
namespace Entropy
{

struct VectorOps
{
    template <typename T>
    using VectorType = MyNamespace::MyVector<T>;

    template <typename T>
    inline static int GetCount(const VectorType<T>& vector)
    {
        return vector.GetCount();
    }

    template <typename T>
    inline static const T& At(const VectorType<T>& vector, int index)
    {
        return vector.At(index);
    }

    template <typename T>
    inline static void Add(VectorType<T>& vector, const T& value)
    {
        vector.Add(value);
    }

    template <typename T>
    inline static void Add(VectorType<T>& vector, T&& value)
    {
        vector.Add(std::move(value));
    }
};

} // namespace Entropy
