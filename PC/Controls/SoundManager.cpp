#include "SoundManager.h"
static DWORD WINAPI ThreadEntry(LPVOID lpParam)
{
	auto* data = reinterpret_cast<std::pair<SoundManager*, int> *>(lpParam);
	if (data)
	{
		data->first->gestionnaireMusic();
		delete data;
	}
	return 0;
}
void SoundManager::gestionnaireMusic()
{
	while (true)
	{
		switch (functionDecider)
		{
			case play_Music:
				this->playMusic();
				functionDecider = -1;
				break;
			case play_SoundTrack:
				this->playSoundTrack();
				functionDecider = -1;
				break;
			case stop_Music:
				functionDecider = -1;
				break;
			case stop_SoundTrack:
				functionDecider = -1;
				break;
			
		}
		Sleep(1);
	}
	
}
SoundManager::SoundManager()
{
	musicPlayerOutput = new QAudioOutput;
	musicPlayer = new QMediaPlayer;

	soundTrackPlayerOutput = new QAudioOutput;
	soundTrackPlayer = new QMediaPlayer;
	//connect(musicPlayer, &QMediaPlayer::mediaStatusChanged, this, &SoundManager::onMediaStatusChanged);
	//--------------------------Magouille a frank---------------------//
	////////////////////////////////////////////////////////////
	 // Create a pair to store MyClass instance and the argument
	auto* data = new std::pair<SoundManager*, int>(this, 42);

	// Create a thread and pass the entry point function
	HANDLE threadHandle = CreateThread(nullptr, 0, ThreadEntry, data, 0, nullptr);

	if (threadHandle == nullptr)
	{
		std::cerr << "Error creating thread.\n";
	}

}


SoundManager::~SoundManager()
{
	delete musicPlayer;
	delete musicPlayerOutput;
	delete soundTrackPlayer;
	delete soundTrackPlayerOutput;
}
void SoundManager::playMusic()
{
	QString path = "";
	switch (music)
	{
		case introMusic:// music d'intro
			path = "debug/Music/RaftWarsIntroMusic.mp3";
			break;
		case gameMusic:// music de jeu (niveau 1 à 5)
			path = "debug/Music/LevelMusic.mp3";
			break;
		case victoryMusic:// Victory music
			path = "debug/Music/VictoryMusic.mp3";
			break;
		case rightRound:// RIGHT ROUND TBNKKK
			path = "debug/Music/Right_Round.mp3";
			break;
		/*default:
			QString path =
			break;*/
	}
	musicPlayer->setSource(QUrl(path));
	musicPlayer->setAudioOutput(musicPlayerOutput);
	musicPlayerOutput->setVolume(0.7);
	musicPlayer->play();

}
void SoundManager::playSoundTrack()
{
	QString path = "";
	switch (soundTrack)
	{
		case canonSoundEffect:// canonball soundEffect
			path = "debug/Music/CanonSoundEffect.mp3";
			break;
		case explosionSoundEffect:// explosion (when rocket hit character) soundEffect
			path = "debug/Music/explosionSoundEffect.mp3";
			break;
		case timerBombSoundEffect:// grenade 3sec timer + explosion
			path = "debug/Music/timerbomb3sec.mp3";
			break;
		case warDrumSoundEffect:// war drum soundEffect
			path = "debug/Music/WarDrumSoundEffect.mp3";
			break;
		case selectionSoundEffect:
			path = "debug/Music/selectionclicksoundeffect30.mp3";
			break;
		case mouseClickEffect:
			path = "debug/Music/mouseSoundClic30.mp3";
			break;
			/*default:
				QString path =
				break;*/
	}
	soundTrackPlayer->setSource(QUrl(path));
	soundTrackPlayer->setAudioOutput(soundTrackPlayerOutput);
	soundTrackPlayerOutput->setVolume(0.8);
	soundTrackPlayer->play();
	// faire que ça loop
}
void SoundManager::stopMusic()// should stop the currentmedia (soundEffect or music) that is active
{
	
	musicPlayer->stop();
	
	
}
void SoundManager::stopSoundTrack()
{
	soundTrackPlayer->stop();
}
//void SoundManager::loopMusic(int music, float volumeIntensity)
//{
//	//playMusic(music, volumeIntensity)
//}