# ofxRoughlySceneMenerger
発展途上。

class scene0 :public baseClass{
public: 
};

class scene1 :public baseClass{
public: 
};
			
		
class scene2 :public baseClass{
public: 
};

ofxRoughlySceneMenerger roughlySceneMenerger;
	baseClass* ptr =  new scene0;
	roughlySceneMenerger.addScenes(ptr,new(scene1),new(scene2));
	roughlySceneMenerger.addScenes(ptr,new(scene1));
	roughlySceneMenerger.removeScenesPack(0);
 
  roughlySceneMenerger.update() //PackingAllScene update
  roughlySceneMenerger.update("scene0") //scene0 update
