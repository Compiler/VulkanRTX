
CXX = g++
C++_VERSION = c++17
CXXFLAGS = -std=$(C++_VERSION) -Wall -w -g -static-libgcc -static-libstdc++

OUT_DIR = bin
LAUNCHER_NAME = LukeRTX
SRC_DIR = src
ENTRY_POINT = src/main.cpp

#Libs
VULKAN_ROOT = C:/VulkanSDK/1.2.154.1/
VULKAN_INC = extern/Vulkan/Include/
VULKAN_LIB = $(VULKAN_ROOT)Lib32/

GLAD_ROOT = extern/glad/
GLAD_INC = $(GLAD_ROOT)include
GLAD_SRC = $(GLAD_ROOT)src

GLFW_ROOT = extern/glfw-3.3.2/MinGWmingw32/
GLFW_INC = $(GLFW_ROOT)include
GLFW_LIB = $(GLFW_ROOT)lib
GLFW_SRC = $(GLFW_ROOT)../src

GLM_ROOT = extern/glm/

STBIMAGE_ROOT = extern/stbimage

INC= -I $(SRC_DIR) -I $(GLFW_INC) -I $(STBIMAGE_ROOT) -I $(GLM_ROOT) -I$(VULKAN_INC)
LIBS = -L $(GLFW_LIB) -L$(VULKAN_LIB)
LINKS = -lglfw3 -lgdi32 -lvulkan-1 -lpthread

#========================OBJECTS========================#
STARTUP_OBJS = $(OUT_DIR)/Startup.o
RENDERING_OBJS = $(OUT_DIR)/Window.o
CORE_OBJS = $(OUT_DIR)/RenderCore.o $(OUT_DIR)/EngineCore.o
OBJS = $(CORE_OBJS) $(ENGINE_CORE_OBJS) $(RENDERING_OBJS) $(STARTUP_OBJS)


ALL_SETTINGS = $(CXX) $(CXXFLAGS) $(LIBS) $(INC) 


main: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -DDEBUG_MODE -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe
	
release: $(ENTRY_POINT) $(OBJS)
	$(ALL_SETTINGS) -DRELEASE_MODE -o $(OUT_DIR)/$(LAUNCHER_NAME) $^ $(LINKS)
	./$(OUT_DIR)/$(LAUNCHER_NAME).exe

$(CORE_OBJS): $(OUT_DIR)/%.o: src/Cores/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(RENDERING_OBJS): $(OUT_DIR)/%.o: src/Rendering/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

$(STARTUP_OBJS): $(OUT_DIR)/%.o: src/Startup/%.cpp
	$(ALL_SETTINGS) -c $< -o $@  

  
