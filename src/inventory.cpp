#include "inventory.h"
#include "Monstruo.h"
#include <algorithm>
#include <vector>



bool inventory::agregarItem( Velom& velom) {
        if (veloms.size() < maxSize) {
            veloms.push_back(velom);
            return true;
        }
        return false;
    }

bool inventory::eliminarItem(const Velom& velom) {
        auto it = find(veloms.begin(), veloms.end(), velom);
        if (it != veloms.end()) {
            veloms.erase(it);
            return true;
        }
        return false;
    }

void inventory::mostrarInventario() const {
        for (const auto& velom : veloms) {
            cout <<"tienes a: "<< velom.getNombre() << endl;
        }
}
