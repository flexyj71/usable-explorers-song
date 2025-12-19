#include <Geode/Geode.hpp>
#include <Geode/modify/LevelTools.hpp>
#include <Geode/modify/SongSelectNode.hpp>
#include <Geode/modify/MoreSearchLayer.hpp>

using namespace geode::prelude;

class $modify(LevelTools) {
	static gd::string getAudioFileName(int id) {
		switch (id) {
		default: return LevelTools::getAudioFileName(id);
		case 22: return "ExplorersCut.mp3"_spr;
		}
	}
};

class $modify (SongSelectNode)
{
    void audioNext(cocos2d::CCObject* p0)
    {
		if (m_selectedSongID != 22)
		{
   			m_selectedSongID++;
	    	getLevelSettings()->m_level->m_audioTrack = m_selectedSongID;
			return SongSelectNode::updateAudioLabel();        
    		SongSelectNode::audioNext(p0);
    
		}
	}
};

$on_mod(Loaded) {
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92276), { 0x83, 0xf8, 0x16 });
	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0x92283), { 0xba, 0x16, 0x00, 0x00, 0x00 });
}
