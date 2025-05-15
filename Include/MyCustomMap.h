// Copyright (c) Entropy Software LLC
// This file is licensed under the MIT License.
// See the LICENSE file in the project root for more information.

// Dummy Map class to show how the default vector type can be changed

#pragma once

#include <unordered_map>

namespace MyNamespace
{

template <typename TKey, typename TValue>
class MyMap
{
public:
    inline void AddUnique(const TKey& key, const TValue& value) { _m.emplace(key, value); }
    inline void AddUnique(const TKey& key, TValue&& value) { _m.emplace(key, std::move(value)); }

    inline void AddOrUpdate(const TKey& key, const TValue& value) { _m[key] = value; }
    inline void AddOrUpdate(const TKey& key, TValue&& value) { _m[key] = std::move(value); }

private:
    std::unordered_map<TKey, TValue> _m;
};

} // namespace MyNamespace

// MapOps must be in the Entropy namespace and have this exact interface
namespace Entropy
{

struct MapOps
{
    template <typename TKey, typename TValue>
    using MapType = MyNamespace::MyMap<TKey, TValue>;

    template <typename TKey, typename TValue>
    inline static void AddUnique(MapType<TKey, TValue>& map, const TKey& key, const TValue& value)
    {
        map.AddUnique(key, value);
    }

    template <typename TKey, typename TValue>
    inline static void AddUnique(MapType<TKey, TValue>& map, const TKey& key, TValue&& value)
    {
        map.AddUnique(key, std::move(value));
    }

    template <typename TKey, typename TValue>
    inline static void AddOrUpdate(MapType<TKey, TValue>& map, const TKey& key, const TValue& value)
    {
        map.AddOrUpdate(key, value);
    }

    template <typename TKey, typename TValue>
    inline static void AddOrUpdate(MapType<TKey, TValue>& map, const TKey& key, TValue&& value)
    {
        map.AddOrUpdate(key, std::move(value));
    }
};

} // namespace Entropy
