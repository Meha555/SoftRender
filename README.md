# SoftRender

基于Shader的软件渲染器

a Shader-based software render for learning

| 模块名   | 内容                                          | 类型       |
| :------- | :-------------------------------------------- | :--------- |
| Base     | Camera、Transform、Mesh、Vertex 等基础类      | 静态库     |
| Material | 材质系统：BlinnMaterial、PBRMaterial、Texture | 静态库     |
| Shader   | 着色器基类与实现：BlinnShader、PBRShader      | 静态库     |
| Pipeline | 渲染管线：Graphics、RenderLoop、StateMachine  | 静态库     |
| UI       | Qt 界面组件：EnvTab、ModelTab、RenderWidget   | 静态库     |
| App      | 主程序入口：main.cpp                          | 可执行文件 |



知乎文章上的版本请查看oldversion分支


![text](https://github.com/SilverClawko/SoftRender/blob/newVersion/ss1.png)
![text](https://github.com/SilverClawko/SoftRender/blob/newVersion/ss3.png)
![text](https://github.com/SilverClawko/SoftRender/blob/newVersion/ss4.png)



## 特性/Features

* 使用Qt编写的ui界面  /  UI written by Qt
* 基于Shader的可编程管线 / Shader-based
* 优化的光栅化算法 / Optimized rasterization algorithm
* SutherlandHodgeman裁剪算法 / Homogeneous clipping based on SutherlandHodgeman algorithm
* 可切换的正面背面剔除 / Switchable back face culling
* 基础阴影 / Base Shadowmap
* 标准光照模型 / Blinn-Phong Shader
* PBR金属工作流 / PBR metalness workflow
* obj模型文件加载 / Load obj file
* 自由设置模型参数 / Customizable modelmatrix
* 自由设置材质参数 / Customizable material
* 切线空间的法线采样 / Tangent space normal map

![text](https://github.com/SilverClawko/SoftRender/blob/newVersion/ss2.png)

* 立方体贴图与天空盒 / Cubemap and Skybox
* 基于图像的照明 / Image-based Lighting

## 安装/Install

Qt 5.12.3 + VS2017环境下打开sln文件直接编译
