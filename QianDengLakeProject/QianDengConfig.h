#ifndef QIANDENGLAKE_QIANDENGLAKECONFIG_H
#define QIANDENGLAKE_QIANDENGLAKECONFIG_H

#include <string>
#include <vector>
#include <fstream>

///全局设置信息
class QianDengLakeConfig {
private:
    // 序列化内容
    std::string editorFont;
    std::string uiFont;

    ///构建配置文件
    std::string buildConfig();
    ///读取配置文件信息
    bool readConfig();
    ///修改配置文件信息
    bool changeConfig();
    ///检查配置文件版本与QianDengLakeProject版本是否一致，不一致需要重新配置
    bool checkConfigVersion();
};

#endif // QIANDENGLAKE_QIANDENGLAKECONFIG_H
