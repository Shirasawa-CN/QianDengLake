//
// Created by shirasawa on 2022/12/31.
//

#ifndef QIANDENGLAKE_QIANDENGLAKEPROJECT_H
#define QIANDENGLAKE_QIANDENGLAKEPROJECT_H

#include <QString>
#include <QFile>
#include <string>
#include <vector>

class QianDengLakeProject
{
private:
    enum Language
    {
        Cpp,
        C,
        Rust,
        Qt,
    };
    // 编译器配置信息
    //
    typedef struct BuildInfo
    {
        // 编译器名称
        std::vector<std::string> complier;
        // 构建路径
        std::string buildPath;
        // 编译器构建配置
        std::vector<std::string> complier_info;
    } buildInfo;

    typedef struct ProjectInfo
    {
        std::string projectName;
        std::vector<Language> languages;
        BuildInfo buildInfo;
    } projectInfo;
};

#endif // QIANDENGLAKE_QIANDENGLAKEPROJECT_H
