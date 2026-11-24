#ifndef COMPLETE_ROVER_H
#define COMPLETE_ROVER_H

#include <memory>
#include <utility>
#include <vector>

template <typename InputMaterial, typename OutputMaterial>
class Rover {
private:
    std::vector<std::unique_ptr<InputMaterial>> m_storage;

public:
    // Převzetí vlastnictví balíku přes std::unique_ptr (bez kopírování dat)
    void loadMaterial(std::unique_ptr<InputMaterial> material) {
        if (material) {
            m_storage.push_back(std::move(material));
        }
    }

    // Zpracování surovin a vrácení pole unique_ptr na výsledné produkty
    std::vector<std::unique_ptr<OutputMaterial>> processMaterialInStorage() {
        std::vector<std::unique_ptr<OutputMaterial>> processed;
        processed.reserve(m_storage.size());

        for (auto& itemPtr : m_storage) {
            if (itemPtr) {
                processed.push_back(std::make_unique<OutputMaterial>(*itemPtr));
            }
        }

        m_storage.clear(); // Automaticky uvolní paměť vstupních materiálů
        return processed;
    }

    // Efektivní přesun celého nákladu do jiného vozítka bez kopírování
    void transferStorageTo(Rover<InputMaterial, OutputMaterial>& targetRover) {
        for (auto& itemPtr : m_storage) {
            if (itemPtr) {
                targetRover.loadMaterial(std::move(itemPtr));
            }
        }
        m_storage.clear();
    }

    void printStorageInfo() const {
        for (auto it = m_storage.begin(); it != m_storage.end(); ++it) {
            if (*it) {
                (*it)->printInfo();
            }
        }
    }
};

#endif //COMPLETE_ROVER_H
