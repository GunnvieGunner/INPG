#ifndef CATALOGUE_HPP_
#define CATALOGUE_HPP_

#include <array>
#include <string>
#include <map>
#include <vector>
// Biblioteka <functional> zawiera definicję szablonu klasy `std::function`.
#include <functional>

class Product {
public:
    Product(std::string id, std::string name, double price) :
            id_(id), name_(name), price_(price) {}

    std::string get_id() const { return id_; }

    std::string get_name() const { return name_; }

    double get_price() const { return price_; }

private:
    std::string id_;
    std::string name_;
    double price_;
};

std::string to_string(const Product& product);

class Catalogue {
public:
    using inventory_t = std::map<std::string, Product>;

    Catalogue(const inventory_t& inventory = inventory_t{})
            : inventory_(inventory) {}

    void add_product(const Product& product) { inventory_.emplace(product.get_id(), product); }

    bool contains(std::string id) const { return (inventory_.find(id) != inventory_.end()); }

    std::vector<Product> get_products_with_appropriate_price(std::function<bool(double)> predicate) const;

    std::vector<Product> get_products_by_name_part(std::string chunk, bool ignoreCase = false) const;

private:
    inventory_t inventory_;
};

#endif /* CATALOGUE_HPP_ */
