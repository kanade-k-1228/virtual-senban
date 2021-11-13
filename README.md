# virtual-senban

## 環境構築

1. このリポジトリをローカルにクローン
   - `cd`
   - `git clone https://github.com/kanade-k-1228/open-gl-test.git`
2. 各種ツールのインストール
   - g++, gdb, make, cmake, clang-format
   - `sudo apt-get update`
   - `sudo apt-get install build-essential gdb cmake cmake-format`
3. OpenGL のインストール
   - `sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev`
4. VSCode を開く
   - `code open-gl-test`
5. 拡張機能を入れる
   - 右下のポップアップで出てくる、「ワークスペース」推奨の拡張機能を入れる
     - ワークスペース推奨の拡張機能は`.vscode/extensions.json` に書いてある
     - VSCode は C++のファイルを見つけると`C/C++ Extension Pack` を勧めてくるが、使わない機能が多く含まれているので入れないほうがいい
6. 拡張機能 : `CMake Tools` の設定
   - `Select a Kit for open-gl-test` というポップアップで出てきたら、`GCC` から始まるものを選択する
     - 複数見つかったら、バージョンの新しいものを選択
   - 下のステータスバーから
     - `ℹ️ CMake:` → `Debug`
     - `🛠️` → `GCC ~~`
     - `[all]` → `[main]`
7. Build と Debug の実行
   - 下のステータスバー
     - 歯車マーク `⚙` → Build が実行される
     - 虫マーク `🐞` → Debug が実行される
8. clang-format のパスを通す
   - `clang-format` があるファイルを探す
     - `whereis clang-format`
   - 実行結果をコピーして、
     - 自分の環境だと `/usr/bin/clang-format`
   - 設定にパスを書く
     - ` Ctrl + Shift + P` で出てきた検索バーから、 `settings.json` を検索して開く
     - ファイルの末尾の `}` の前に一行追加して、 `"clang-format.executable": "/usr/bin/clang-format",` を書き足す
