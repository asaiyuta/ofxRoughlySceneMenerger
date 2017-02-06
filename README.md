# ofxRoughlySceneManager
発展途上。

* クラス名を勝手に取ってきて、管理するよ。やったね！

```cpp
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

ofxRoughlySceneManager roughlySceneManager;
baseClass* ptr =  new scene0;
roughlySceneManager.addScenes(ptr,new(scene1),new(scene2));
//どっちでもいいよ。とりあえず突っ込んでね。
//内部的にシーンパックが生成されるよ。
//scenePack index 0 
roughlySceneManager.addScenes(ptr,new(scene1));
//scenePack index 1

roughlySceneManager.removeScenesPack(0);
//これでシーンパックは削除。切り詰められるよ。

roughlySceneManager.update() //パックのすべてを　update　するよ。
roughlySceneManager.update("scene0") //stringで指定したクラス名のシーンを一つ。　update　するよ。

roughlySceneManager.getAllScenesName();　//現在登録されてるシーンをすべてstringで返すよ。
roughlySceneManager.getScenesName(index) //インデックス番号に登録されたシーンパック中身の名前。
roughlySceneManager.changeScenes(index) //そのインデックスのシーンパックに切り替わるよ。
roughlySceneManager.changeScenes(index,true) //そのインデックスのシーンパックに切り替わるよ。 + setupをするよ。
```