#pragma once
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>
#include <iostream>

namespace core {

class ServiceLocator {
public:
    template<typename T>
    static void provide(std::shared_ptr<T> service) {
        getServices()[typeid(T)] = std::static_pointer_cast<void>(service);
    }

    template<typename T>
    static std::shared_ptr<T> get() {
        auto& services = getServices();
        auto it = services.find(typeid(T));
        if (it != services.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        std::cerr << "[ServiceLocator Error] Requested unregistered service type: "
                  << typeid(T).name() << std::endl;
        return nullptr;
    }

private:
    static std::unordered_map<std::type_index, std::shared_ptr<void>>& getServices() {
        static std::unordered_map<std::type_index, std::shared_ptr<void>> services;
        return services;
    }
};

} // namespace core
