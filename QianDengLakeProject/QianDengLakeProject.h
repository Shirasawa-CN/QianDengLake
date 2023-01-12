#ifndef QIANDENGLAKE_QIANDENGLAKEPROJECT_H
#define QIANDENGLAKE_QIANDENGLAKEPROJECT_H

#include <QString>
#include <QFile>
#include <string>
#include <vector>

///Version 0.0.1
class QianDengLakeProject {
public:
    ///读取项目配置文件信息
    bool readProjectInfo();
    ///创建项目
    bool createProject();
    ///写入初始化项目配置文件
    bool writeInitProjectInfo();
    ///修改项目配置文件
    bool changeProjectInfo();

private:
    enum Language {
        Cpp,
        C,
        Rust,
        Qt,
    };
    // 编译器配置信息
    struct BuildInfo {
        // 编译器名称
        std::vector<std::string> complier;
        // 构建路径
        std::string buildPath;
        // 编译器构建配置
        std::vector<std::string> complierInfo;
    };

    struct ProjectInfo {
        std::string projectName;
        std::vector<Language> languages;
        BuildInfo buildInfo;
    };
};

#endif // QIANDENGLAKE_QIANDENGLAKEPROJECT_H
