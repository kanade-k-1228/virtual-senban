# virtual-senban

## 環境構築

1. ツールのインストール
    - g++, gdb, make, cmake, clang-format
    - `sudo apt-get update`
    - `sudo apt-get install build-essential gdb cmake cmake-format`
2. OpenGL のインストール
    - `sudo apt-get update`
    - `sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev`
3. このリポジトリをローカルにクローン
    - `cd`
    - `git clone https://github.com/kanade-k-1228/virtual-senban.git`
4. VSCode を開く
    - `cd [your project name]`
    - `code .`
5. 拡張機能を入れる
    - 右下のポップアップで出てくる
    - `.vscode/extensions.json` に書いてある
6. CMake Tools の Build Variant を設定
    - 下のステータスバーから `ℹ️ CMake:` のところをクリック
    - `Debug` を選択
7. Build Kits を設定
    - 🛠️ をクリック
    - `GCC ~~` を選択
8. Build の実行
    - ⚙ のアイコンをクリック
9. Target の選択
    - `[all]` をクリック
    - `[main]`を選択
9. Debug の実行
    - 🐞のアイコンをクリック
10. clang-format のパスを通す
