//
//  DataScoures.cpp
//  LoveEveryDayToElimate
//
//  Created by xingweihao456 on 15-7-20.
//
//

#include "DataScoures.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"
#include "cocos2d.h"
USING_NS_CC;
using namespace rapidjson;
static Json* jsons=NULL;
Json::Json()
{

}
Json* Json::GetInstance()
{
    if (!jsons) {
        jsons=new Json();
    }
    return jsons;
}
void Json::ParseJson()
{
    FileUtils * fu=FileUtils::getInstance();
    string wrPath=fu->getWritablePath()+"Level.json";
    if (!fu->isFileExist(wrPath)) {
        string LevelPath=fu->fullPathForFilename("Level.json");
        string pContentFile=fu->getStringFromFile(LevelPath);
        FILE * file=fopen(wrPath.c_str(), "w");
        if (file) {
            fputs(pContentFile.c_str(), file);
            fclose(file);
        }
    }
    string wrPathContent=fu->getStringFromFile(wrPath);
    rapidjson::Document doc;
    doc.Parse<kParseDefaultFlags>(wrPathContent.c_str());
    if (doc.HasParseError()) {
        log("doc.HasParseError():%s",doc.GetParseError());
    }
    rapidjson::Value&array=doc["Levels"];
    if (array.IsArray()) {
        int count=array.Size();
        for (int i=0; i<count; i++) {
            DataScoures  * _data=new DataScoures();
            datas.push_back(_data);
        }
        for (int i=0; i<count; i++) {
            rapidjson::Value & type=array[i];
            rapidjson::Value & PassTheScore=type["PassTheScore"];
            datas.at(i)->PassTheScore=PassTheScore.GetInt();
            rapidjson::Value & HightSocre=type["HightSocre"];
            datas.at(i)->HightSocre=HightSocre.GetInt();
            rapidjson::Value & Unclock=type["Unclock"];
            datas.at(i)->Unclock=Unclock.GetInt();
        }
    }
}

void Json::printDatas()
{
    int count=datas.size();
    for (int i=0; i<count; i++) {
        log("%d,%d,%d\n",datas.at(i)->HightSocre,datas.at(i)->PassTheScore,datas.at(i)->Unclock);
    }
   
}
void Json::ParseUpdateJson()
{
    
    FileUtils * fu=FileUtils::getInstance();
    string wrPath=fu->getWritablePath()+"Level.json";
    if (!fu->isFileExist(wrPath)) {
        string LevelPath=fu->fullPathForFilename("Level.json");
        string pContentFile=fu->getStringFromFile(LevelPath);
        FILE * file=fopen(wrPath.c_str(), "w");
        if (file) {
            fputs(pContentFile.c_str(), file);
            fclose(file);
        }
    }
    string wrPathContent=fu->getStringFromFile(wrPath);
    rapidjson::Document doc;
    doc.Parse<kParseDefaultFlags>(wrPathContent.c_str());
    if (doc.HasParseError()) {
        log("doc.HasParseError():%s",doc.GetParseError());
    }
    datas.at(3)->Unclock=1;
    rapidjson::Value&array=doc["Levels"];
    if (array.IsArray()) {
        int count=array.Size();
        for (int i=0; i<count; i++) {
            rapidjson::Value & type=array[i];
            rapidjson::Value & PassTheScore=type["PassTheScore"];
            PassTheScore.SetInt( datas.at(i)->PassTheScore);
            rapidjson::Value & HightSocre=type["HightSocre"];
            HightSocre.SetInt(datas.at(i)->HightSocre);
            datas.at(i)->HightSocre=HightSocre.GetInt();
            rapidjson::Value & Unclock=type["Unclock"];
            Unclock.SetInt(datas.at(i)->Unclock);
        }
    }
    StringBuffer buffer;
    rapidjson::Writer<StringBuffer>writer(buffer);
    doc.Accept(writer);
    FILE * file=fopen(wrPath.c_str(), "wb");
    if (file) {
        fputs(buffer.GetString(), file);
        fclose(file);
    }
}

