#pragma once

#include <string>
#include <vector>

struct Item
{
    ::std::string name;
    int sellIn;
    int quality;
};

class GildedRose
{

public:
    ::std::vector<Item> items;
    explicit GildedRose(::std::vector<Item> && items_);
    explicit GildedRose(::std::vector<Item> const& items_);

    /**
     * <p>
     * <h3>Regular:</h3>
     * <tt><ul>
     *   <li> sellIn >  0 -> sellIn -= 1, quality -= 1
     *   <li> sellIn == 0 -> sellIn -= 1, quality -= 2
     *   <li> sellIn <  0 -> sellIn -= 1, quality -= 2
     * </ul>
     * <p>
     *   Always: quality == 0 -> stays 0 <br>
     *   Regular applies to every item unless specified otherwise.
     * </p></tt>
     * </p>
     *
     * <p>
     * <h3>AgedBrie:</h3>
     * <tt><ul>
     *   <li> sellIn >  0 -> sellIn -= 1, quality += 1
     *   <li> sellIn == 0 -> sellIn -= 1, quality += 2
     *   <li> sellIn <  0 -> sellIn -= 1, quality += 2
     * </ul>
     *  Allways: quality == 50 -> stays 50 <br>
     *  Allways: quality == 49 -> caps at 50 <br>
     * </p></tt>
     *
     * <p>
     * <h3>Sulfuras:</h3>
     * <tt><ul>
     *   <li> sellIn >  0 -> all stays
     *   <li> sellIn == 0 -> all stays
     * </ul></tt>
     * </p>
     *
     * <p>
     * <h3>BackstagePasses:</h3>
     * <tt><ul>
     *   <li> sellIn == 10 -> quality += 2
     *   <li> sellIn ==  6 -> quality += 2
     *   <li> sellIn ==  5 -> quality += 3
     *   <li> sellIn ==  0 -> quality = 0
     *   <li> sellIn < 0 -> quality = 0
     * </ul></tt>
     * </p>
     */
    void updateQuality();
};
