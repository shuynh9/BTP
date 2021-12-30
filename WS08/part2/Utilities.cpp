// Workshop 8 - Smart Pointers
// 2019/11 - Cornel
// 2021//11/14 - Sophia Huynh


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i{ 0 }; i < desc.size(); i++) {
			for (size_t j{ 0 }; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* temp = new Product(desc[i].desc, price[j].price);
					temp->validate();
					priceList += temp;
					delete temp;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i{ 0 }; i < desc.size(); i++) {
			for (size_t j{ 0 }; j < price.size(); j++) {
				if (price[j].code == desc[i].code) {
					unique_ptr<Product> temp2(new Product(desc[i].desc, price[j].price));
					temp2->validate();
					priceList += temp2; // will automatically deallocate
				}
			} 
		}
		return priceList;
	}
}