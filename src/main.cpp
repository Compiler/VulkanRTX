
#include <Tools/Logging.h>
#include <RenderCore.h>
int main(){
    
    WARN("Program begin");
    lk::RenderCore core;

    core.load();
    int count = 0;
    while(count++ < 560000000){
        core.update();
        core.render();
    }

    WARN("Program Unloading...");
    core.unload();

    return 0;

}