///-------------------------------------------------------------------------------------------------
// file: AssetManager.h
//
// author: William Barry
// date: 10/28/2019
//
// summary:	The Asset Manager
///-------------------------------------------------------------------------------------------------
#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_
#pragma once

#include "ISystem.h"
#include "Asset.h"

class AssetManager final : public ISystem
{
private:
	std::map<STRCODE, Asset*> assets;

protected:

    void initialize() override;
    void update(float deltaTime) override;

    friend class GameEngine;
    DECLARE_SINGLETON(AssetManager)

public:
	void loadLevelAssets(json::JSON& node);
	void unloadLevelAssets();

	Asset* CreateAssetT();

	Asset* getAssetByGUID(std::string& guid);	//TODO: Confirm with everyone and remove this?
	Asset* getAssetBySTRCODE(STRCODE);
};

#endif