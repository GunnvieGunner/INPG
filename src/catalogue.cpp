#include "catalogue.hpp"
#include <array>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>

std::string to_string(const Product& product) {
    std::ostringstream oss;
    oss << product.get_name() << " [" << product.get_id() << "] : "
        << std::setprecision(2) << std::fixed << "$" << product.get_price();
    return oss.str();
}

std::vector<Product> Catalogue::get_products_with_appropriate_price(std::function<bool(double)> predicate) const {
    inventory_t filteredInventory;
    std::vector<Product> products;

    for (const auto& entry : inventory_) {
        const auto& product = entry.second;
        if (predicate(product.get_price())) {
            products.push_back(product);
        }
    }

//  Poniżej implementacja z użyciem standardowych algorytmów (w tym przypadku
//  dłuższa i mniej czytelna...).
//
//  std::copy_if(inventory_.begin(), inventory_.end(),
//      std::inserter(filteredInventory, filteredInventory.end()),
//      [&predicate](const auto& entry) {
//    const auto& product = entry.second;
//    return predicate(product.get_price());}
//  );
//
//  std::transform(filteredInventory.begin(), filteredInventory.end(), std::back_inserter(products),
//      [](const auto& entry) { return entry.second;});


    return products;
}

std::vector<Product> Catalogue::get_products_by_name_part(std::string chunk, bool ignoreCase) const {
    std::vector<Product> products;

    for (const auto& entry : inventory_) {
        const auto& product = entry.second;
        std::string name = product.get_name();

        std::string name_transformed = name;
        std::string chunk_transformed = chunk;

        if (ignoreCase) {
            std::transform(name.begin(), name.end(), name_transformed.begin(), ::tolower);
            std::transform(chunk.begin(), chunk.end(), chunk_transformed.begin(), ::tolower);
        }

        bool containsChunk = (name_transformed.find(chunk_transformed) != std::string::npos);
        if (containsChunk) {
            products.push_back(product);
        }
    }

    return products;
}
