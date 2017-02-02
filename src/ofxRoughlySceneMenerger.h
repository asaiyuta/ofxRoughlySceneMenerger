#pragma once
#include "baseClass.h"
#include <Vector>
#include <iostream>
#include <memory>

class Scenes{
public:
	Scenes(){}
	template <typename ...scenes>
	Scenes(scenes... all){
		setScenes(all...);
	}
	~Scenes(){
	}
	
	inline std::shared_ptr<baseClass> operator [] (const std::size_t& index) const{
		return this -> rawScenes[index];
	}
	
	inline std::shared_ptr<baseClass> at(const std::size_t& index) const{
		return this -> rawScenes[index];
	}
	
	std::size_t size() const{
		return this -> rawScenes.size();
	}
	
	std::string getPackScenesNames() const{
		std::string names;
		for(auto e :rawScenes){
			names += (std::string)*e + "\n";
		}
		return names;
	}
	
	std::string getSceneName(const std::size_t& index){
		if(rawScenes.size() >= index){
		return (std::string)*rawScenes[index];
		}
		return "";
	}
	
private:
	template <typename sceneOne,typename ...sceneRest>
 	void setScenes(sceneOne one,sceneRest... rest){
		std::shared_ptr<baseClass> ptr(one);
		rawScenes.push_back(ptr);
		setScenes(rest...);
	}
	template <typename sceneOne>
	void setScenes(sceneOne one){
		std::shared_ptr<baseClass> ptr(one);
		rawScenes.push_back(ptr);
		rawScenes.shrink_to_fit();
	}
//	std::vector<baseClass*> rawScenes;
	std::vector<std::shared_ptr<baseClass> > rawScenes;
};


class ScenesPack{
public: 
	ScenesPack(){}	
	~ScenesPack(){}
	template <typename ...scenes>
	void add(scenes... all){
		Scenes* uncharted = new Scenes(all...);
		rawScenesPack.push_back(uncharted);
	}
	
	void remove(std::size_t index){
		delete rawScenesPack[index];
		rawScenesPack.erase(rawScenesPack.begin() + index);
		rawScenesPack.shrink_to_fit();
	}
	
	inline Scenes operator [] (const std::size_t& index) const{
		return *rawScenesPack[index];
	}
	
	std::size_t size() const{
		return this -> rawScenesPack.size();
	}
	
	std::string getPackScenesNames(const std::size_t& index) const{
		if(rawScenesPack.size() >= index){
			return rawScenesPack[index] -> getPackScenesNames();
		}
		return "";
	}
	
	std::string getSceneName(const std::size_t& packIndex ,const std::size_t& sceneIndex) const{
		if(rawScenesPack.size() >= packIndex){
			return rawScenesPack[packIndex] -> getSceneName(sceneIndex);
		}
		return "";
	}
	
	std::shared_ptr<baseClass> getSceneFromName(const std::string& name){
		for(int packNum = 0 ; packNum < rawScenesPack.size() ; ++packNum){
			for(int sceneNum = 0 ; sceneNum < rawScenesPack[packNum] -> size() ; ++sceneNum){
				if(name == rawScenesPack[packNum] -> getSceneName(sceneNum)){
					return rawScenesPack[packNum] -> at(sceneNum);
				}
			}
		}
		return nullptr;
	}
	
	bool isExistenceName(const std::string& name)const{
		bool isExsitence(false);
			for(int packNum = 0 ; packNum < rawScenesPack.size() ; ++packNum){
				for(int sceneNum = 0 ; sceneNum < rawScenesPack[packNum] -> size() ; ++sceneNum){
					isExsitence |= (name == rawScenesPack[packNum] -> getSceneName(sceneNum));
				}
			}
		return 	isExsitence;
	}

	std::vector<Scenes*> rawScenesPack;
};

class ofxRoughlySceneMenerger{
public:
	ofxRoughlySceneMenerger()
	: currentScenesNum(0)
	{}
	~ofxRoughlySceneMenerger(){}
	template <typename ...scenes>
	void addScenes(scenes... all){
		scenesPack.add(all...);
	}
	
	void removeScenesPack(std::size_t targetNum){
		scenesPack.remove(targetNum);
	}
	
	void changeScenes(std::size_t sceneNum,bool isSetup = false){
		currentScenesNum = sceneNum;
		if(isSetup){
			setup();
		}
	}
    
    std::size_t getNumOfPack() const{
        return this -> scenesPack.size();
    }
	
	std::string getAllScenesName() const{
		std::string str;
		for(int i = 0 ; i < scenesPack.size() ; ++i){
			str += "INDEX " + std::to_string(i) + "\n" + getScenesName(i);
		}
		return str;
	}
	
	std::string getScenesName(std::size_t index) const{
		return scenesPack.getPackScenesNames(index);
	}
	
	std::string getCurrentScenesName(){
		return getScenesName(currentScenesNum);
	}
	
	void setup(std::string sceneName){
		if(scenesPack.isExistenceName(sceneName)){
			scenesPack.getSceneFromName(sceneName) ->setup();	
		}
	}
	
	void update(std::string sceneName){
		if(scenesPack.isExistenceName(sceneName)){
			scenesPack.getSceneFromName(sceneName) ->update();	
		}
	}
	
	void drive(std::string sceneName){
		if(scenesPack.isExistenceName(sceneName)){
			scenesPack.getSceneFromName(sceneName) ->drive();	
		}
	}
	
	void draw(std::string sceneName){
		if(scenesPack.isExistenceName(sceneName)){
			scenesPack.getSceneFromName(sceneName) ->draw();	
		}
	}
	
	void setup(){
		for(int i = 0 ; i < scenesPack[currentScenesNum].size() ; ++i){
			scenesPack[currentScenesNum][i] -> setup();
		}
	}
	
	void update(){
		for(int i = 0 ; i < scenesPack[currentScenesNum].size() ; ++i){
			scenesPack[currentScenesNum][i] -> update();
		}
	}
	
	void drive(){
		for(int i = 0 ; i < scenesPack[currentScenesNum].size() ; ++i){
			scenesPack[currentScenesNum][i] -> drive();
		}
	}
	
	void draw(){
		for(int i = 0 ; i < scenesPack[currentScenesNum].size() ; ++i){
			scenesPack[currentScenesNum][i] -> draw();
		}
	}
	
private:
	std::size_t currentScenesNum;
 	ScenesPack scenesPack;
};


