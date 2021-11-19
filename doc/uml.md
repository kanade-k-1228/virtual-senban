# UML

## 現実の旋盤のシーケンス図

```plantuml
actor User
participant Moter
participant Bite
participant Work

activate User
User -> Moter : Start
activate Moter
Moter -> Work : Rotate
activate Work
User -> Bite : Move
activate Bite
Bite -> Work : Cut
User -> Moter : Stop
deactivate Moter
deactivate Bite
```

## クラス図

```plantuml
class Cylinder{
    radians[]
}
```

## ゲームの一般的な構造

```plantuml
@startuml
left to right direction
actor Player
rectangle "Interface Devices" {
  usecase Display   as UI1
  usecase Speaker   as UI2
  usecase Keyboard  as UI3
  usecase Mouse     as UI4
}
rectangle "Driver Engine" {
  usecase GPU       as DE1
  usecase SoundCard as DE2
  usecase IO        as DE3
}

Player <-- UI1
Player <-- UI2
Player --> UI3
Player --> UI4

UI1 <-- DE1
UI2 <-- DE2
UI3 --> DE3
UI4 --> DE3

DE1 <-- Game : OpenGL
DE2 <-- Game : OpenAL
DE3 --> Game

@enduml
```
