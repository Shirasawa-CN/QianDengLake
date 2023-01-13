#ifndef QIANDENGLAKE_QIANDENGLAKECONFIG_H
#define QIANDENGLAKE_QIANDENGLAKECONFIG_H

#include <string>
#include <vector>
#include <fstream>
//#include <format>

const std::string version = "0.0.1";
const std::string configPath = "~/.qiandenglake/config.json";
///全局设置信息
class QianDengLakeConfig {
private:
    // 序列化内容
    std::string editorFont;
    std::string uiFont;
    std::string editorFontSize;
    std::string defaultCComplierPath;
    std::string defaultCppComplierPath;
    std::string defaultRustComplierPath;
    std::string defaultQtPath;

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
