# ofxRoughlySceneMenerger
発展途上。
*クラス名を勝手に取ってきて、管理するよ。やったね！

class scene0 :public baseClass{
public: 
    void setup(){hogehoge...}
    void update(){hogehoge...}
    void drive(){hogehoge...}
    void draw(){hogehoge...}
};
//とりあえずbaseClassは継承してね。

class scene1 :public baseClass{
    hogehoge...
};					
class scene2 :public baseClass{
    hogehoge...: 
};

ofxRoughlySceneMenerger roughlySceneMenerger;
baseClass* ptr =  new scene0;
roughlySceneMenerger.addScenes(ptr,new(scene1),new(scene2));
//どっちでもいいよ。とりあえず突っ込んでね。
//内部的にシーンパックが生成されるよ。
//scenePack index 0 
roughlySceneMenerger.addScenes(ptr,new(scene1));
//scenePack index 1

roughlySceneMenerger.removeScenesPack(0);
//これでシーンパックは削除。切り詰められるよ。

roughlySceneMenerger.update() //パックのすべてを　update　するよ。
roughlySceneMenerger.update("scene0") //stringで指定したクラス名のシーンを一つ。　update　するよ。

roughlySceneMenerger.getAllScenesName();　//現在登録されてるシーンをすべてstringで返すよ。
roughlySceneMenerger.getScenesName(index) //インデックス番号に登録されたシーンパック中身の名前。
roughlySceneMenerger.changeScenes(index) //そのインデックスのシーンパックに切り替わるよ。
roughlySceneMenerger.changeScenes(index,true) //そのインデックスのシーンパックに切り替わるよ。 + setupをするよ。
