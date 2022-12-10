#include "gilded_rose/GildedRose.hh"

#include <functional>

GildedRose::GildedRose(::std::vector<Item> const &items) :
    items(items) {}

GildedRose::GildedRose(::std::vector<Item> &&items) :
    items(::std::move(items)) {}

void GildedRose::updateQuality()
{
    // Special cases
    static constexpr char const* BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
    static constexpr char const* BRIE = "Aged Brie";
    static constexpr char const* SULFURAS = "Sulfuras, Hand of Ragnaros";

    for(auto& item : items) {
        // For regular items std::minus
        // For aged brie std::plus
        auto regular = [&item](auto sign){
            if(item.sellIn > 0) {
                item.quality = sign(item.quality, 1);
            } else {
                item.quality = sign(item.quality, 2);
            }
        };

        if(item.name == BRIE) {
            // aged brie has the opposite rules from regular
            regular(std::plus<>{});
        } else if(item.name == BACKSTAGE_PASS) {
            if(item.sellIn > 5) {
                item.quality += 2;
            } else if(item.sellIn > 0) {
                item.quality += 3;
            } else {
                item.quality = 0;
            }
        } else if(item.name == SULFURAS) {
            // sellIn is decreased at the end of the function
            // but has to stay the same for this item
            item.sellIn += 1;
        } else {
            // Generic rules
            regular(std::minus<>{});
        }

        // Generic rules
        item.sellIn -= 1;
        if(item.quality < 0) {
            item.quality = 0;
        }
        if(item.name != SULFURAS && item.quality > 50) {
            item.quality = 50;
        }
    }
}
