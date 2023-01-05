2010.08.30 坂井弘亮

本ファイルは書籍
「リンカ・ローダ実践開発テクニック」(坂井弘亮，2010/08，CQ出版社)
の付録です．

■ column

追加コラムです．〆切的な問題で，本文には掲載されなかったものです．
印刷して，指定のページにはさんでおくといいかもしれません．

とくに以下の文章は，なかなか説明されている資料も無いため一読しておくといいかも
しれません．

column-sec6-p152.txt
「MEMORYコマンドによるアドレス割り当ての制御」

column-sec10-p249.txt
「グローバル・ポインタの利用」

■ src

本文中で紹介されているテキスト(主にプログラムのソースコードや出力結果など)と
その他もろもろです．

本ファイルは無保証です．個人の責任の下で利用してください．
ファイルの製作者・出版社は，本ソースコードを利用することで発生するいかなる
責任も負いません．

一部のソースコードは，FreeBSD/NetBSD/GNU+Linuxなどからの抜粋(流用)です．
これらのソースコードの著作権は，流用元に属します．流用元については書籍の本文を
参照してください．とくに説明の無いものは，FreeBSDもしくはFreeBSDに添付されて
配布されているGNU製ツールのソースコードからの流用です．

それ以外のソースコードは書籍の執筆者である坂井が作成したものです．
個人の責任の下で，自由に利用して構いません．

ソースコード中には，書籍中で紹介していない実験用のものなども含まれています．
自由に利用してください．

以下がソースコード一覧です．
リスト番号は，書籍の本文中での番号です．
図については一部のみ以下一覧に掲載してありますが，出力結果などの多くのものは
srcディレクトリ以下にありますので，必要ならば探してみるといいかもしれません．

--------------------------------------------------------------------------------
リスト番号	内容						ソースコード
--------------------------------------------------------------------------------
リスト1.1	hello.c						src/hello/hello.c
リスト1.2	gcc -v の結果					src/hello/gcc-v.out
リスト1.3	size hello の結果				src/hello/size.out
リスト1.4	objdump -h hello の結果				src/hello/objdump.out
リスト1.5	/usr/src/usr.bin/size/size.c より抜粋		src/hello/size_aout.c
リスト1.6	struct exec の定義(imgact_aout.h より抜粋)	src/hello/imgact_aout.h
リスト1.7	hello の先頭部分の16進ダンプ			src/hello/hello_dump.txt
リスト1.8	/usr/src/contrib/binutils/binutils/size.c より抜粋
								src/hello/size_elf.c
リスト1.9	objdump -p hello の結果				src/hello/objdump-p.out
リスト1.10	様々な変数の定義(values_sub.c)			src/values/values_sub.c
リスト1.11	様々な変数の定義(values.c)			src/values/values.c
リスト1.12	nm values_sub.o の結果				src/values/values_sub_nm.out
リスト1.13	nm values の結果				src/values/values_nm.out
リスト1.14	objdump -h values の結果			src/values/objdump.out
リスト1.15	values の実行結果				src/values/values.out
リスト1.16	strip values の実行結果				src/values/strip.out
リスト1.17	リンカスクリプトの雛型				---
リスト1.18	エントリポイントについて(info ld より抜粋)	---
リスト1.19	ENTRY()の指定(elf_i386.x より抜粋)		---
--------------------------------------------------------------------------------
リスト2.1	ELFファイル解析用サンプル(elfsamp.c)		src/elfsamp/elfsamp.c
リスト2.2	ELFファイル解析用サンプル(main.c)		src/elfsamp/main.c
リスト2.3	ELF32ヘッダ(elf32.h)				---
リスト2.4	readelf -h elfsamp.o の結果			src/elfsamp/readelf-o-h.out
リスト2.5	brandelf.c より抜粋				---
リスト2.6	ELF32用セクションヘッダ(elf32.h)		---
リスト2.7	readelf -S elfsamp.o の結果			src/elfsamp/readelf-o-S.out
リスト2.8	readelf -x 8 elfsamp.o の結果			src/elfsamp/readelf-o-x.out
リスト2.9	セクション名一覧の表示の例(readsec.c)		src/elfsamp/readsec.c
リスト2.10	ELF32用プログラムヘッダ(elf32.h)		---
リスト2.11	readelf -l elfsamp の結果			src/elfsamp/readelf-l.out
リスト2.12	自身のELFヘッダを読み込む例(elfread.c)		src/elfread/elfread.c
リスト2.13	シンボルテーブル用構造体(ELF32)			---
リスト2.14	readelf -s elfsamp.o の結果			src/elfsamp/readelf-o-s.out
リスト2.15	再配置エントリ(ELF32)				---
リスト2.16	readelf -r elfsamp.o の結果			src/elfsamp/readelf-o-r.out
リスト2.17	ELF形式のダンププログラムの例(elfdump.c)	src/elfsamp/elfdump.c
リスト2.18	elfdump elfsamp.o の実行結果			src/elfsamp/elfdump-o.exec
リスト2.19	elfdump elfsamp の実行結果			src/elfsamp/elfdump.exec
--------------------------------------------------------------------------------
リスト3.1	アーカイブヘッダの定義(ar.h より抜粋)		src/ar/ar.h
リスト3.2	4.4BSD由来のアーカイブ(bsdar.a)			src/ar/bsdar.a
リスト3.3	GNU binutils のアーカイブ(gnuar.a)		src/ar/gnuar.a
リスト3.4	アーカイブファイルのダンプ(readname.c)		src/ar/readname.c
リスト3.5	アーカイブファイルの解析(ardump.c)		src/ar/ardump.c
リスト3.6	オブジェクトファイル(ardump.o)の解析例		src/ar/ardump.exec
リスト3.7	ライブラリアーカイブ(/usr/lib/libc.a)の解析例	src/ar/ardump.exec2
リスト3.8	main() 関数(main.c)				src/link/main.c
リスト3.9	サンプルファイル１(samp1.c)			src/link/samp1.c
リスト3.10	サンプルファイル２(samp2.c)			src/link/samp2.c
リスト3.11	サンプルファイル３(samp3.c)			src/link/samp3.c
リスト3.12	サンプルファイル４(samp4.c)			src/link/samp4.c
リスト3.13	サンプルファイル２の修正(samp2.c)		src/link/samp2d.c
---		checksym.c					src/checksym/checksym.c
--------------------------------------------------------------------------------
リスト4.1	配列とポインタ(pointer.c)			src/pointer/pointer.c
図4.2		nm pointer の結果				src/pointer/pointer.nm
図4.3		objdump -h pointer の結果			src/pointer/pointer.od
リスト4.2	const 定義した変数に値を代入する(const.c)	src/const/const.c
リスト4.3	const 定義した変数に値を代入する(const_sub.c)	src/const/const_sub.c
図4.8		nm const の結果					src/const/const.nm
図4.9		objdump -h const の結果				src/const/const.od
リスト4.4	リンカスクリプトの修正				src/const/elf_i386.diff
図4.12		nm noconst の結果				src/const/noconst.nm
図4.13		objdump -h noconst の結果			src/const/noconst.od
リスト4.5	シンボルタイプについて(info nm より抜粋)	---
リスト4.6	変数 b の参照(const_b.c)			src/const/const_b.c
リスト4.7	変数 num の参照(layer.c)			src/layer/layer.c
リスト4.8	変数 num の定義(layer_sub1.c)			src/layer/layer_sub1.c
リスト4.9	変数 num の参照(layer_sub2.c)			src/layer/layer_sub2.c
図4.27		nm liblayer.a の結果				src/layer/liblayer.a.nm
図4.31		nm liblayer_local.a の結果			src/layer/liblayer_local.a.nm
図4.35		nm layer_lib.o の結果				src/layer/layer_lib.o.nm
図4.38		nm layer_lib_local.o の結果			src/layer/layer_lib_local.o.nm
リスト4.10	変数 num を操作しない(layer2.c)			src/layer/layer2.c
図4.41		シンボルが重複する場合				src/layer/layer_lib2.o.comp
リスト4.11	NetBSD/hpcsh 用リンカスクリプト(ehl-elf.x より抜粋)
								---
リスト4.12	PROVIDE()の指定(elf_i386.x より抜粋)		---
リスト4.13	シンボルのアドレスの表示(edata.c)		src/edata/edata.c
図4.46		objdump -h edata の結果				src/edata/edata.od
リスト4.14	初期化を任意に行なう(initialize.c)		src/initialize/initialize.c
図4.47		initialize の実行結果				src/initialize/initialize.comp
								src/initialize/initialize.exec
リスト4.15	do_ctors()の定義(crtbegin.cより抜粋)		---
リスト4.16	ctor_end[]の定義(crtend.c より抜粋)		---
リスト4.17	.ctors セクションの定義(elf_i386.xより抜粋)	---
リスト4.18	関数の自動呼び出し(ctors.c)			src/ctors/ctors.c
図4.48		ctors のアドレス配置				src/ctors/ctors.comp
								src/ctors/ctors.nm
								src/ctors/ctors.od
リスト4.19	do_dtors()の定義(crtbegin.cより抜粋)		---
リスト4.20	atexit() による _fini() の登録(crt1.c:_start()より抜粋)
								---
リスト4.21	exit()の定義(exit.cより抜粋)			---
リスト4.22	constructor, destructor 属性の利用(constructor.c)
								src/constructor/constructor.c
--------------------------------------------------------------------------------
リスト5.1	ソースファイルの例(main.c)			src/linksamp/main.c
リスト5.2	ソースファイルの例(lib1.c)			src/linksamp/lib1.c
リスト5.3	ソースファイルの例(lib2.c)			src/linksamp/lib2.c
リスト5.4	objdump による解析(main.o)			src/linksamp/main.od
リスト5.5	objdump による解析(lib1.o)			src/linksamp/lib1.od
リスト5.6	objdump による解析(lib2.o)			src/linksamp/lib2.od
リスト5.7	objdump による解析(linksamp)			src/linksamp/linksamp.od
リスト5.8	簡単なリンカスクリプトの例(sample.lds)		src/linksamp/sample.lds
リスト5.9	objdump による解析(otherscr)			src/linksamp/otherscr.od
--------------------------------------------------------------------------------
リスト6.1	簡単なリンカスクリプトの例(sample.lds)		src/linksamp/sample.lds
リスト6.2	命令書き換えの例(overwrite.c)			src/linksamp/overwrite.c
リスト6.3	シンボル作成のサンプルスクリプト(addr.lds)	src/linksamp/addr.lds
リスト6.4	シンボル作成のサンプルプログラム(addr.c)	src/linksamp/addr.c
図6.6		addr の解析結果(抜粋)				src/linksamp/addr.od
図6.7		addr の実行結果					src/linksamp/addr.out
リスト6.5	シンボル衝突のサンプルスクリプト(conflict.lds)	src/linksamp/conflict.lds
リスト6.6	シンボル衝突のサンプルプログラム(conflict.c)	src/linksamp/conflict.c
図6.10		conflict の解析結果(抜粋)			src/linksamp/conflict.od
図6.11		conflict の実行結果				src/linksamp/conflict.out
リスト6.7	定義可能な初期値ありの領域			---
リスト6.8	定義不可能な初期値ありの領域			---
リスト6.9	変数作成のサンプルスクリプト(valiable.lds)	src/linksamp/valiable.lds
リスト6.10	変数作成のサンプルプログラム(valiable.c)	src/linksamp/valiable.c
リスト6.11	FILL()の利用方法				---
リスト6.12	FILLEXPの利用方法				---
図6.13		valiable の解析結果(抜粋)			src/linksamp/valiable.od
図6.14		valiable の実行結果				src/linksamp/valiable.out
リスト6.13	セクションの作成書式				---
リスト6.14	セクションの記述				---
リスト6.15	LMA指定のサンプルスクリプト(lma.lds)		src/linksamp/lma.lds
図6.16		lma の解析結果(抜粋)				src/linksamp/lma.od
図6.17		nm lma の結果					src/linksamp/lma.nm
--------------------------------------------------------------------------------
リスト7.1	リンクの順番のサンプルプログラム(ordermain.c, ...)
								src/order/ordermain.c
								src/order/order1.c
								src/order/order2.c
リスト7.2	重複シンボルのサンプルプログラム(dupmain.c, ...)
								src/duplicate/dupmain.c
								src/duplicate/duptest1.c
								src/duplicate/duptest2.c
								src/duplicate/dup1.c
								src/duplicate/dup2.c
リスト7.3	バイナリデータの焼き込み(binary.c)		src/binary/binary.c
図7.21		nm binary の結果				src/binary/binary.nm
図7.22		objdump -h binary の結果			src/binary/binary.od
リスト7.4	.incbin の利用(incbin.s)			src/binary/incbin.s
リスト7.5	usr/initramfs_data.S 中のコメント		---
リスト7.6	リンカスクリプト(bindata.scr)			src/binary/bindata.scr
--------------------------------------------------------------------------------
リスト8.1	ELF形式のロード部分(imgact_elf.c)		---
図8.1		man execl より抜粋				---
図8.2		readelf -S /bin/ls の結果			src/loader/ls.shdr
図8.3		readelf -S /usr/bin/gcc の結果			src/loader/gcc.shdr
リスト8.2	リンカスクリプトの修正				src/loader/ldscript.diff
図8.4		readelf -l /bin/ls の結果			src/loader/ls.phdr
リスト8.3	フラグ変更用のプログラム(chflg.c)		src/loader/chflg.c
リスト8.4	_start()の先頭部分(crt1.c)			---
リスト8.5	(stack_sample.c)				src/stack/stack_sample.c
リスト8.6	(stack_sample.s)				src/stack/stack_sample.s
リスト8.7	簡易ローダ(loader.c)				src/loader/loader.c
リスト8.8	ロード対象のサンプルプログラム(sample.c)	src/loader/sample.c
図8.7		簡易ローダの実行結果				src/loader/loader.out
--------------------------------------------------------------------------------
リスト9.1	コアダンプ作成用プログラム(down.c)		src/core/down.c
図9.3		実行形式のセクション構成			src/core/down.readelf
図9.4		コアダンプの解析				src/core/core.readelf
リスト9.2	elf_puthdr()					---
リスト9.3	elf_putnote()					---
リスト9.4	Elf_Note の定義(elf_common.h)			---
リスト9.5	prstatus_t の定義(procfs.h)			---
リスト9.6	struct reg の定義(reg.h)			---
リスト9.7	struct fpreg の定義(reg.h)			---
リスト9.8	prpsinfo_t の定義(procfs.h)			---
図9.5		コアダンプの解析				src/core/nm.out
図9.6		変数 count 付近のダンプ				---
リスト9.9	実行再開用のプログラム(continue.c)		src/continue/continue.c
リスト9.10	実行再開の実験用サンプルプログラム(calc.c)	src/continue/calc.c
図9.7		calc.c の実行結果				src/continue/calc.comp
								src/continue/calc.out
図9.10		実行の再開					src/continue/continue.out
リスト9.A	_setjmp()/_longjmp() の利用例(setjmp.c)		src/setjmp/setjmp.c
図9.A		setjmp.c の実行結果				src/setjmp/setjmp.out
リスト9.B	_setjmp()/_longjmp() のソース(_setjmp.S)	src/setjmp/_setjmp.S
リスト9.C	_setjmp() 呼び出し後にスタックが破壊される例(setjmp2.c)
								src/setjmp/setjmp2.c
図9.B		setjmp2.c の実行結果				src/setjmp/setjmp2.out
--------------------------------------------------------------------------------
リスト10.1	逆アセンブル用のサンプルプログラム(rasm.c)	src/rasm/rasm.c
リスト10.2	逆アセンブル用のサンプルプログラム(rasm2.c)	src/rasm/rasm2.c
リスト10.3	rasm.o の逆アセンブル結果			src/rasm/rasm.o.ra
リスト10.4	rasm の逆アセンブル結果				src/rasm/rasm.ra
リスト10.5	rasm.o のセクション，再配置テーブル，シンボルテーブル
								src/rasm/rasm.o.re
リスト10.6	rasm2.o のシンボルテーブル			src/rasm/rasm2.o.re
リスト10.7	rasm のシンボルテーブル				src/rasm/rasm.re
リスト10.8	i386依存の定義(/usr/include/machine/elf.h)	---
リスト10.9	weak シンボルの定義の例(weak.c)			src/weak/weak.c
リスト10.10	グローバルシンボルの定義の例(global.c)		src/weak/global.c
リスト10.11	weak シンボルの利用の例(main.c)			src/weak/main.c
リスト10.12	global.o をリンクした場合の実行結果		src/weak/global.exec
リスト10.13	global.o をリンクしなかった場合の実行結果	src/weak/noglobal.exec
リスト10.14	実行形式 global のシンボルテーブル(抜粋)	src/weak/global.nm
リスト10.15	実行形式 noglobal のシンボルテーブル(抜粋)	src/weak/noglobal.nm
リスト10.16	ライブラリアーカイブを利用した場合の実行結果	src/weak/global_a.exec
リスト10.17	man syscall					---
リスト10.18	__syscall() の呼び出し				---
リスト10.19	syscall()の定義(抜粋)				---
リスト10.20	システムコール用ライブラリ(syscall.s)		src/linker/syscall.s
リスト10.21	文字列表示用ライブラリ(service.c)		src/linker/service.c
リスト10.22	スタートアップ(crt.c)				src/linker/crt.c
リスト10.23	サンプルプログラム(main.c)			src/linker/main.c
リスト10.24	サンプルプログラム(sample.c)			src/linker/sample.c
リスト10.25	サンプルプログラム(sample2.c)			src/linker/sample2.c
リスト10.26	サンプルプログラムの実行結果			src/linker/sample.exec
リスト10.27	シンボル解決用ライブラリ(linklib.h)		src/linker/linklib.h
リスト10.28	シンボル解決用ライブラリ(linklib.c)		src/linker/linklib.c
リスト10.29	ダイナミックリンカ(dynlink.c)			src/linker/dynlink.c
リスト10.30	ダイナミックリンカの実行結果			src/linker/dynlink.exec
リスト10.31	実行形式用のリンカ(linker.c)			src/linker/linker.c
リスト10.32	実行形式用リンカの実行結果			src/linker/linker.exec
リスト10.33	リンカで作成した実行形式の実行結果		src/linker/sample2.exec
リスト10.34	PowerPC用のシンボル解決				---
--------------------------------------------------------------------------------
リスト11.1	ライブラリのサンプルプログラム(sample.c)	src/shared/sample.c
リスト11.2	ライブラリ利用のサンプルプログラム(main.c)	src/shared/main.c
図11.7		sample_shared の実行結果			src/shared/sample_shared.exec
図11.11		sample_static の実行結果			src/shared/sample_static.exec
図11.13		readelf -a sample_pic.o の出力結果		src/shared/sample_pic.o.re
リスト11.3	i386の再配置種別(/usr/include/machine/elf.h より抜粋)
								---
図11.14		objdump -d sample_pic.o の出力結果		src/shared/sample_pic.o.ra
図11.15		readelf -a libsample.so.1 の出力結果		src/shared/libsample.so.1.re
リスト11.4	Elf32_Dyn の定義(elf32.h より抜粋)		---
リスト11.5	d_tag が持つ値(elf_common.h より抜粋)		---
図11.16		libsample.so.1 の .got セクションのダンプ結果	src/shared/libsample.so.1.got
図11.17		objdump -d libsample.so.1 の出力結果		src/shared/libsample.so.1.ra
図11.18		readelf -a sample_shared の出力結果		src/shared/sample_shared.re
図11.19		objdump -d sample_shared の出力結果		src/shared/sample_shared.ra
図11.20		sample_shared の .got セクションのダンプ結果	src/shared/sample_shared.got
リスト11.6	.rtld_start の定義(i386/rtld_start.S)		---
リスト11.7	_rtld()の定義(rtld.c)				---
リスト11.8	init_rtld()の定義(rtld.c)			---
リスト11.9	digest_phdr()の定義(rtld.c)			---
リスト11.10	digest_dynamic()の定義(rtld.c)			---
リスト11.11	relocate_objects()の定義(rtld.c)		---
リスト11.12	init_pltgot()の定義(i386/reloc.c)		---
リスト11.13	_rtld_bind()の定義(rtld.c)			---
リスト11.14	dlopen()/dlsym()/dlclose()の使用例(dlopen.c)	src/shared/dlopen.c
図11.21		dlopen.c の実行結果				src/shared/dlopen.exec
リスト11.15	dlopen()の定義(rtld.c)				---
--------------------------------------------------------------------------------

以上
