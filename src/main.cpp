#include <Tools/Logging.h>
#include <Cores/RenderCore.h>
int main(){
    
    WARN("Program begin");
    Leng::RenderCore core;

    core.load();
    int count = 0;
    while(core.isRunning()){
        core.update();
        core.render();
    }

    WARN("Program Unloading...");
    core.unload();

    return 0;

}