#include "core/application.h"

int main(int argc, char *argv[]) {
    core::Application app(argc, argv);
    return app.exec();
}
