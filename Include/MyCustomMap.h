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
    inline int GetCount() const { return (int)_m.size(); }

    inline void AddUnique(const TKey& key, const TValue& value) { _m.emplace(key, value); }
    inline void AddUnique(const TKey& key, TValue&& value) { _m.emplace(key, std::move(value)); }

    inline void AddOrUpdate(const TKey& key, const TValue& value) { _m[key] = value; }
    inline void AddOrUpdate(const TKey& key, TValue&& value) { _m[key] = std::move(value); }

    inline bool TryGetValue(const TKey& key, TValue* outValue) const
    {
        auto it = _m.find(key);
        if (it == _m.end())
        {
            return false;
        }

        *outValue = it->second;

        return true;
    }

    inline bool TryGetValue(const TKey& key, const TValue** outValue) const
    {
        auto it = _m.find(key);
        if (it == _m.end())
        {
            return false;
        }

        *outValue = &it->second;

        return true;
    }

    // Stl-like iterators are required
    auto begin() const -> decltype(std::declval<const std::unordered_map<TKey, TValue>>().begin())
    {
        return _m.begin();
    }
    auto end() const -> decltype(std::declval<const std::unordered_map<TKey, TValue>>().end()) { return _m.end(); }

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
    inline static int GetCount(const MapType<TKey, TValue>& map)
    {
        return map.GetCount();
    }

    template <typename TKey, typename TValue>
    inline static bool TryGetValue(const MapType<TKey, TValue>& map, const TKey& key, TValue* outValue)
    {
        return map.TryGetValue(key, outValue);
    }

    template <typename TKey, typename TValue>
    inline static bool TryGetValue(const MapType<TKey, TValue>& map, const TKey& key, const TValue** outValue)
    {
        return map.TryGetValue(key, outValue);
    }

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
