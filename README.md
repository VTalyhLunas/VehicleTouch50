# Demo project

## Подготовка окружения

О контенеризации Unreal Engine можно почитать в [официальной документации](https://dev.epicgames.com/documentation/en-us/unreal-engine/container-deployments-and-images-for-unreal-editor-and-unreal-engine).

Так же, можно воспользоваться уже собранными образами для сборки с детальным описанием процесса сборки [на этом ресурсе](https://github.com/adamrehn/ue4-docker).

[Официальная документация](https://dev.epicgames.com/documentation/en-us/unreal-engine/building-unreal-engine-from-source?application_version=5.5) по сборке Unreal Engine

Доступ к исходным кодам Unreal Engine описан в [официальном репозитории](https://github.com/EpicGames)

## Информация о Pixel Streaming

Основной источник информации [официальная документация](https://dev.epicgames.com/documentation/en-us/unreal-engine/pixel-streaming-in-unreal-engine)

## Сборка проекта

1. Клонировать [репозиторий](https://github.com/VTalyhLunas/VehicleTouch50.git)
2. Подготовить проект к сборке выполнив в консоли команду:
	
	```[Путь до Unreal Engine]\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe -projectfiles -project="[Путь до проекта]\VehicleTouch50.uproject" -game -rocket -progress```

3. Собрать проект выполнив в консоли команду:

	```[Путь до Unreal Engine]/Engine/Build/BatchFiles/RunUAT.bat  -ScriptsForProject="[Путь до проекта]/VehicleTouch50.uproject" Turnkey -command=VerifySdk -platform=Win64 -UpdateIfNeeded -EditorIO -EditorIOPort=55078  -project="[Путь до проекта]/VehicleTouch50.uproject" BuildCookRun -nop4 -utf8output -nocompileeditor -skipbuildeditor -cook  -project="[Путь до проекта]/VehicleTouch50.uproject" -target=VehicleTouch50  -unrealexe="[Путь до Unreal Engine]\Engine\Binaries\Win64\UnrealEditor-Cmd.exe" -platform=Win64 -installed -stage -archive -package -build -pak -compressed -prereqs -archivedirectory="[Путь до папки сохранения результата]" -clientconfig=Shipping -nodebuginfo -nocompile -nocompileuat```

4. В *[Путь до папки сохранения результата]* после успешной сборки будет находится собранный проект.
5. Для запуска проекта с Pixel Streaming необходмо запустить исполняемый файл с параметрами:

	```VehicleTouch50.exe -PixelStreamingURL=ws://127.0.0.1:8888 -RenderOffScreen```
