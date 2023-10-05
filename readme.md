# Qt插件开发例子
这个例子中有三个项目分别对应三个文件夹：
+ QtPlugin：不带QWidget的插件
+ QtPluginDemo：加载插件用的**主项目**
+ QtWidgetPlugin：带QWidget的插件

***

编译完成后，将dll拷贝到QtPluginDemo的运行目录下。

QtPluginDemo/plugin目录下存放的是两个插件的一些头文件，如果插件项目中对应的头文件修改后需要覆盖到当前文件夹下的文件。