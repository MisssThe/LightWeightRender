cmake_minimum_required(VERSION 3.20)
project(LightWeightRenderer)

set(CMAKE_CXX_STANDARD 17)

set(GLEW_H ${PROJECT_SOURCE_DIR}/Include/glew/2.2.0_1/include/GL)
set(GLFW_H ${PROJECT_SOURCE_DIR}/Include/glfw/3.3.4/include/GLFW)
set(GLAD_H ${PROJECT_SOURCE_DIR}/Include/glad/include/glad)
set(KH_H ${PROJECT_SOURCE_DIR}/Include/glad/include/KHR)
set(JSON_H ${PROJECT_SOURCE_DIR}/Include/jsoncpp/1.9.4_1/include/json)
set(ASSIMP_H ${PROJECT_SOURCE_DIR}/Include/assimp/5.0.1/include)
set(GLM_H ${PROJECT_SOURCE_DIR}/Include/glm/0.9.9.8/include)
set(IMAGE_H ${PROJECT_SOURCE_DIR}/Include/stb_image/include)
set(FREETYPE_H ${PROJECT_SOURCE_DIR}/Include/freetype/2.11.0/include/freetype2)
#set(FBX_H ${PROJECT_SOURCE_DIR}/Include/FBX/include)
include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H} ${KH_H} ${JSON_H} ${ASSIMP_H} ${GLM_H} ${IMAGE_H} ${FREETYPE_H})

set(GLEW_LINK ${PROJECT_SOURCE_DIR}/Include/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK ${PROJECT_SOURCE_DIR}/Include/glfw/3.3.4/lib/libglfw.3.3.dylib)
set(JSON_LINK ${PROJECT_SOURCE_DIR}/Include/jsoncpp/1.9.4_1/lib/libjsoncpp.24.dylib)
set(ASSIMP_LINK ${PROJECT_SOURCE_DIR}/Include/assimp/5.0.1/lib/libassimp.dylib)
#set(FBX_LINK  ${PROJECT_SOURCE_DIR}/Include/FBX/lib/clang/debug/libfbxsdk.a)
link_libraries(${OPENGL} ${GLFW_LINK} ${GLEW_LINK} ${JSON_LINK} ${ASSIMP_LINK})

add_executable(
        LightWeightRenderer         main.cpp    glad.c
        Source/Module.h
        Utils/Head/ThreadUtil.h     Utils/Source/ThreadUtil.cpp
        Utils/Head/MathUtil.h       Utils/Source/MathUtil.cpp
        Utils/Head/JsonUtil.h       Utils/Source/JsonUtil.cpp
        Utils/Head/LogUtil.h        Utils/Source/LogUtil.cpp
        Utils/Head/TraverUtil.h
        Source/Source/Graph/Window.cpp Source/Head/Graph/Window.h
        Source/Source/Graph/RenderPipeline.cpp Source/Head/Graph/RenderPipeline.h
        Utils/Source/MainLoopUtil.cpp Utils/Head/MainLoopUtil.h
        Source/Source/Graph/BaseRender/Shader.cpp Source/Head/Graph/BaseRender/Shader.h
        Utils/Source/FileUtil.cpp Utils/Head/FileUtil.h
        Utils/Source/StringUtil.cpp Utils/Head/StringUtil.h
        Source/Source/Graph/BaseRender/Material.cpp Source/Head/Graph/BaseRender/Material.h
        Source/Source/Graph/BaseRender/Mesh.cpp Source/Head/Graph/BaseRender/Mesh.h
        Source/Source/Graph/BaseRender/Transform.cpp Source/Head/Graph/BaseRender/Transform.h
        Source/Source/Physics/CollisionDetection.cpp Source/Head/Physics/CollisionDetection.h
        Source/Head/Graph/MeshLoader/BaseLoader.h Source/Source/Graph/MeshLoader/AssimpLoader.cpp
        Source/Head/Graph/MeshLoader/AssimpLoader.h Source/Head/Graph/MeshLoader/GeneralLoader.h
        Source/Source/Graph/MeshLoader/BaseLoader.cpp Source/Source/Extend/TexturePacker.cpp
        Source/Head/Extend/TexturePacker.h Source/Source/Graph/BaseRender/Texture.cpp Source/Head/Graph/BaseRender/Texture.h Utils/Head/SortUtil.h Source/Source/Graph/GraphController/MeshController.cpp Source/Head/Graph/GraphController/MeshController.h Source/Source/Graph/GraphController/ShaderController.cpp Source/Head/Graph/GraphController/ShaderController.h Source/Source/Graph/GraphController/MaterialController.cpp Source/Head/Graph/GraphController/MaterialController.h Source/Source/Graph/RenderObject.cpp Source/Head/Graph/RenderObject.h Source/Source/Extend/UI/Image.cpp Source/Head/Extend/UI/Image.h
        Source/Head/Graph/GraphController/GraphController.h
        Source/Head/Renderer.h Source/Source/Renderer.cpp Source/Source/Extend/InfoPanel.cpp Source/Head/Extend/InfoPanel.h Source/Source/Graph/GraphController/TextureController.cpp Source/Head/Graph/GraphController/TextureController.h Source/Source/Graph/BaseRender/Camera.cpp Source/Head/Graph/BaseRender/Camera.h Source/Source/Graph/GraphController/CameraController.cpp Source/Head/Graph/GraphController/CameraController.h Utils/Source/ConstUtil.cpp Utils/Head/ConstUtil.h Source/Source/Graph/GraphController/AssetController.cpp Source/Head/Graph/GraphController/AssetController.h)
