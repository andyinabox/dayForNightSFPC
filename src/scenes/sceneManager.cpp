//
//  sceneManager.cpp
//  d4nSFPCRunner
//
//  Created by zach on 11/14/15.
//
//

#include "sceneManager.h"
#include "exampleScene.h"
#include "triangleScene.h"
#include "veraAnimatedScene.h"
#include "robbyMolnarScene.h"
#include "robbyRileyScene.h"
#include "yeseulWhitneyScene.h"
#include "johnWhitneyShader01.h"
#include "johnWhitneyShader02.h"
#include "RoyWhitney1.h"
#include "veraFscene.h"
#include "anastasisRileyScene.h"
#include "loloWhitney.h"
#include "loloVera.h"
#include "menkmanJPG1.h"
#include "menkmanPNG1.h"
#include "CooperBauhaus.h"
#include "memoAktenScene.h"
#include "submotionOrchestraScene.h"
#include "manfredMohrP196A.h"
#include "chrisMurielCooper.h"
#include "chrisRileyCascando.h"
#include "veraMolnarTrapezium.h"
#include "loloVera2.h"
#include "cantusFirmusRiley.h"
#include "chrisVeraInterruptions.h"
#include "aaronMarcusHieroglyphB.h"
#include "veraMolnarLines68.h"
#include "Cooper3dText.h"
#include "alexLissamojiWhitney.h"
#include "janVantommeScene.h"
#include "rodrigoBelfort.h"
#include "rachelScene.h"
#include "RileyArcsRoy.h"
#include "robbyMenkmanScene.h"

void sceneManager::setup(){
    scenes.push_back(new CooperBauhaus());  // this might make for a good start scene -Robby & Becca
    scenes.push_back(new RileyArcsRoy());
    scenes.push_back(new rachelScene());
    scenes.push_back(new rodrigoBelfort());
    scenes.push_back(new Cooper3dText());
    scenes.push_back(new chrisVeraInterruptions());
    scenes.push_back(new johnWhitneyShader02());
    scenes.push_back(new chrisRileyCascando());
    scenes.push_back(new chrisMurielCooper());
	
    scenes.push_back(new janVantommeScene());
	scenes.push_back(new memoAktenScene());
    scenes.push_back(new submotionOrchestraScene());
    scenes.push_back(new RoyWhitney1());
    scenes.push_back(new veraFscene());
    scenes.push_back(new robbyMolnarScene() );
    scenes.push_back(new veraAnimatedScene() );
    scenes.push_back(new exampleScene() );
    scenes.push_back(new triangleScene() );
    scenes.push_back(new robbyRileyScene() );
//    scenes.push_back(new robbyMenkmanScene());//in progress
    scenes.push_back(new yeseulWhitneyScene() );
    scenes.push_back(new johnWhitneyShader01());
    scenes.push_back(new anastasisRileyScene());
    scenes.push_back(new loloWhitney());
    scenes.push_back(new loloVera());
    scenes.push_back(new menkmanJPG1());
    scenes.push_back(new menkmanPNG1());
	scenes.push_back(new manfredMohrP196A());
	scenes.push_back(new veraMolnarTrapezium());
    scenes.push_back(new loloVera2());
    scenes.push_back(new cantusFirmusRiley());
	scenes.push_back(new aaronMarcusHieroglyphB());
    scenes.push_back(new veraMolnarLines68());
    scenes.push_back(new alexLissamojiWhitney());
    
    sceneFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);
    codeFbo.allocate(VISUALS_WIDTH, VISUALS_HEIGHT, GL_RGBA, 4);


    
    // disney
    for (auto scene : scenes){
        scene->dimensions.set(0,0,VISUALS_WIDTH, VISUALS_HEIGHT);
        scene->setup();
    }
    
    
//    for (int i = 0; i< scenes.size(); i++){
//        scenes[i]->setup();
//    }
    
    currentScene = 0;
    scenes[currentScene]->reset();
    
    
    
    panel = new ofxPanel();
    panel->setup();
    panel->add(scenes[currentScene]->parameters);
    panel->setPosition(ofGetWidth()-300, 20);

    
    mode = DRAW_SIDE_BY_SIDE;
    
}

void sceneManager::update(){
    scenes[currentScene]->update();
}

void sceneManager::draw(){
    
    
    
    sceneFbo.begin();
    ofClear(0,0,0,255);
    ofPushStyle();
    scenes[currentScene]->draw();
    ofPopStyle();
    ofClearAlpha();
    sceneFbo.end();
    
    
    if (mode == DRAW_SIDE_BY_SIDE){
        ofSetColor(255,255,255);
        sceneFbo.draw(0,0,ofGetHeight(), ofGetHeight());
        
        codeFbo.begin();
        ofClear(50,50,50, 255);
        string codeReplaced = scenes[currentScene]->getCodeWithParamsReplaced();
        ofDrawBitmapString(codeReplaced, 40,40);
        codeFbo.end();
        
        codeFbo.draw(ofGetHeight(), 0,ofGetHeight(), ofGetHeight());
    } else if (mode == DRAW_SINGLE){
        sceneFbo.draw(0,0);
    }
    
    panel->draw();
    
}

void sceneManager::nextScene(bool forward){
	if (forward){
    	currentScene ++;
    	currentScene %= scenes.size();
	} else {
	    currentScene --;
		if (currentScene < 0){
			currentScene = scenes.size() - 1;
		}
	}

    scenes[currentScene]->reset();
    
    
    
    delete panel;
    panel = new ofxPanel();
    panel->setup();
    panel->add(scenes[currentScene]->parameters);
    
    panel->setPosition(ofGetWidth()-300, 20);
}; 

void sceneManager::advanceScene(){
	nextScene(true);
};

void sceneManager::regressScene(){
	nextScene(false);
};
