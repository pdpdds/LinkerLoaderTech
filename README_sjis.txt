2010.08.30 사카이 히로아키

본 파일은 서적
「링커,로더 실전 개발 테크닉」(사카이 히로아키，2010/08，CQ출판사)
의 부록입니다.

■ column

추가 컬럼입니다．마감 날짜 문제로 본문에는 게재되지 않은 내용입니다.   
인쇄해서 지정된 페이지에 끼워 두면 좋을것입니다.

특히 아래 내용은 특별히 설명된 자료가 없기 때문에 한 번 읽어 보는 것이 좋을 것입니다

column-sec6-p152.txt
「MEMORY 커맨드에 따른 어드레스 할당 제어」

column-sec10-p249.txt
「글로벌 포인터의 사용」

■ src

본문에서 소개하고 있는 텍스트(주로 프로그램의 소스코드나 출력결과 등)와  
기타 여러가지입니다.

본 파일의 사용에 대해서는 책임을 지지 않습니다. 개인의 책임하에 사용해 주세요.   
파일의 제작자・출판사는 본 소스코드를 이용해서 발생하는 어떠한 책임도 지지 않습니다.   

잏부 소스코드는 FreeBSD/NetBSD/GNU+Linux 등에서 발췌했습니다. 
이런 소스코드의 저작권은 해당 프로젝트에 있습니다. 해당 프로젝트에 대해서는 서적의 본문을   
참조해 주세요. 특별히 설명이 없는 내용은 FreeBSD 또는 FreeBSD에 첨부되어 배포하는   
GNU 툴의 소스코드가 원 출처입니다.

그 이외의 소스 코드는 서적 집필자인 사카이가 작성한 것입니다.   
개인의 책임 하에 자유롭게 이용해도 괜찮습니다.  

일부 소스 코드는 도서에 소개되지 않은 실험용 코드를 포함합니다.   
자유롭게 이용해 주세요.

다음은 소스 코드 목록입니다.
목록 번호는 책의 본문에서 나온 번호입니다
그림의 경우에는 일부만 책에 게재되어 있습니다만, 출력 결과 등의 많은 그림이   
src 디렉토리 아래에 있으므로 필요하다면 찾아보는 것이 좋습니다.   

--------------------------------------------------------------------------------
리스트 번호	내용						소스코드
--------------------------------------------------------------------------------
리스트1.1	hello.c						src/hello/hello.c
리스트1.2	gcc -v 의 결과					src/hello/gcc-v.out
리스트1.3	size hello 의 결과				src/hello/size.out
리스트1.4	objdump -h hello 의 결과				src/hello/objdump.out
리스트1.5	/usr/src/usr.bin/size/size.c 에서 발췌		src/hello/size_aout.c
리스트1.6	struct exec 의 정의(imgact_aout.h 에서 발췌)	src/hello/imgact_aout.h
리스트1.7	hello 의 선두부분의 선두부분 16진수 덤프			src/hello/hello_dump.txt
리스트1.8	/usr/src/contrib/binutils/binutils/size.c 에서 발췌
								src/hello/size_elf.c
리스트1.9	objdump -p hello 의 결과				src/hello/objdump-p.out
리스트1.10	다양한 변수의 정의(values_sub.c)			src/values/values_sub.c
리스트1.11	다양한 변수의 정의(values.c)			src/values/values.c
리스트1.12	nm values_sub.o 의 결과				src/values/values_sub_nm.out
리스트1.13	nm values 의 결과				src/values/values_nm.out
리스트1.14	objdump -h values 의 결과			src/values/objdump.out
리스트1.15	values 의 실행결과				src/values/values.out
리스트1.16	strip values 의 실행결과				src/values/strip.out
리스트1.17	링커스크립트의 모형				---
리스트1.18	엔트리 포인트에 대해(info ld 에서 발췌)	---
리스트1.19	ENTRY()의 지정(elf_i386.x 에서 발췌)		---
--------------------------------------------------------------------------------
리스트2.1	ELF 파일 해석용 샘플(elfsamp.c)		src/elfsamp/elfsamp.c
리스트2.2	ELF 파일 해석용 샘플(main.c)		src/elfsamp/main.c
리스트2.3	ELF32 헤더(elf32.h)				---
리스트2.4	readelf -h elfsamp.o 의 결과			src/elfsamp/readelf-o-h.out
리스트2.5	brandelf.c 에서 발췌			---
리스트2.6	ELF32용 섹션 헤더(elf32.h)		---
리스트2.7	readelf -S elfsamp.o의 결과			src/elfsamp/readelf-o-S.out
리스트2.8	readelf -x 8 elfsamp.o의 결과			src/elfsamp/readelf-o-x.out
리스트2.9	섹션 이름 목록 표시의 예(readsec.c)		src/elfsamp/readsec.c
리스트2.10	ELF32용 프로그램 헤더(elf32.h)		---
리스트2.11	readelf -l elfsamp 의 결과			src/elfsamp/readelf-l.out
리스트2.12	자신의 ELF 헤더를 읽어들이는 예(elfread.c)		src/elfread/elfread.c
리스트2.13 심볼 테이블용 구조체(ELF32)			---
리스트2.14	readelf -s elfsamp.o 의 결과			src/elfsamp/readelf-o-s.out
리스트2.15 재배치 엔트리(ELF32)				---
리스트2.16	readelf -r elfsamp.o 의 결과			src/elfsamp/readelf-o-r.out
리스트2.17	ELF 형식의 덤프 프로그램 예(elfdump.c)	src/elfsamp/elfdump.c
리스트2.18	elfdump elfsamp.o 의 실행결과			src/elfsamp/elfdump-o.exec
리스트2.19	elfdump elfsamp 의 		src/elfsamp/elfdump.exec
--------------------------------------------------------------------------------
리스트3.1	アーカイブヘッダの定義(ar.h より抜粋)		src/ar/ar.h
리스트3.2	4.4BSD由来のアーカイブ(bsdar.a)			src/ar/bsdar.a
리스트3.3	GNU binutils のアーカイブ(gnuar.a)		src/ar/gnuar.a
리스트3.4	アーカイブファイルのダンプ(readname.c)		src/ar/readname.c
리스트3.5	アーカイブファイルの解析(ardump.c)		src/ar/ardump.c
리스트3.6	オブジェクトファイル(ardump.o)の解析例		src/ar/ardump.exec
리스트3.7	ライブラリアーカイブ(/usr/lib/libc.a)の解析例	src/ar/ardump.exec2
리스트3.8	main() 関数(main.c)				src/link/main.c
리스트3.9	サンプルファイル１(samp1.c)			src/link/samp1.c
리스트3.10	サンプルファイル２(samp2.c)			src/link/samp2.c
리스트3.11	サンプルファイル３(samp3.c)			src/link/samp3.c
리스트3.12	サンプルファイル４(samp4.c)			src/link/samp4.c
리스트 3.13	サンプルファイル２の修正(samp2.c)		src/link/samp2d.c
---		checksym.c					src/checksym/checksym.c
--------------------------------------------------------------------------------
리스트 4.1	配列とポインタ(pointer.c)			src/pointer/pointer.c
図4.2		nm pointer の結果				src/pointer/pointer.nm
図4.3		objdump -h pointer の結果			src/pointer/pointer.od
리스트 .2	const 定義した変数に値を代入する(const.c)	src/const/const.c
리스트 4.3	const 定義した変数に値を代入する(const_sub.c)	src/const/const_sub.c
図4.8		nm const の結果					src/const/const.nm
図4.9		objdump -h const の結果				src/const/const.od
리스트 4.4	リンカスクリプトの修正				src/const/elf_i386.diff
図4.12		nm noconst の結果				src/const/noconst.nm
図4.13		objdump -h noconst の結果			src/const/noconst.od
리스트 4.5	シンボルタイプについて(info nm より抜粋)	---
리스트 4.6	変数 b の参照(const_b.c)			src/const/const_b.c
리스트 4.7	変数 num の参照(layer.c)			src/layer/layer.c
리스트 4.8	変数 num の定義(layer_sub1.c)			src/layer/layer_sub1.c
리스트 4.9	変数 num の参照(layer_sub2.c)			src/layer/layer_sub2.c
図4.27		nm liblayer.a の結果				src/layer/liblayer.a.nm
図4.31		nm liblayer_local.a の結果			src/layer/liblayer_local.a.nm
図4.35		nm layer_lib.o の結果				src/layer/layer_lib.o.nm
図4.38		nm layer_lib_local.o の結果			src/layer/layer_lib_local.o.nm
リスト4.10	変数 num を操作しない(layer2.c)			src/layer/layer2.c
図4.41		シンボルが重複する場合				src/layer/layer_lib2.o.comp
리스트 4.11	NetBSD/hpcsh 用リンカスクリプト(ehl-elf.x より抜粋)
								---
리스트 4.12	PROVIDE()の指定(elf_i386.x より抜粋)		---
리스트 4.13	シンボルのアドレスの表示(edata.c)		src/edata/edata.c
図4.46		objdump -h edata の結果				src/edata/edata.od
리스트 4.14	初期化を任意に行なう(initialize.c)		src/initialize/initialize.c
図4.47		initialize の実行結果				src/initialize/initialize.comp
								src/initialize/initialize.exec
리스트 4.15	do_ctors()の定義(crtbegin.cより抜粋)		---
리스트 4.16	ctor_end[]の定義(crtend.c より抜粋)		---
리스트 4.17	.ctors セクションの定義(elf_i386.xより抜粋)	---
리스트 4.18	関数の自動呼び出し(ctors.c)			src/ctors/ctors.c
図4.48		ctors のアドレス配置				src/ctors/ctors.comp
								src/ctors/ctors.nm
								src/ctors/ctors.od
리스트 4.19	do_dtors()の定義(crtbegin.cより抜粋)		---
리스트 4.20	atexit() による _fini() の登録(crt1.c:_start()より抜粋)
								---
리스트 4.21	exit()の定義(exit.cより抜粋)			---
리스트 4.22	constructor, destructor 属性の利用(constructor.c)
								src/constructor/constructor.c
--------------------------------------------------------------------------------
리스트 5.1	ソースファイルの例(main.c)			src/linksamp/main.c
리스트 5.2	ソースファイルの例(lib1.c)			src/linksamp/lib1.c
리스트 5.3	ソースファイルの例(lib2.c)			src/linksamp/lib2.c
리스트 5.4	objdump による解析(main.o)			src/linksamp/main.od
리스트 5.5	objdump による解析(lib1.o)			src/linksamp/lib1.od
리스트 5.6	objdump による解析(lib2.o)			src/linksamp/lib2.od
리스트 5.7	objdump による解析(linksamp)			src/linksamp/linksamp.od
리스트 5.8	簡単なリンカスクリプトの例(sample.lds)		src/linksamp/sample.lds
리스트 5.9	objdump による解析(otherscr)			src/linksamp/otherscr.od
--------------------------------------------------------------------------------
리스트 6.1	簡単なリンカスクリプトの例(sample.lds)		src/linksamp/sample.lds
리스트 6.2	命令書き換えの例(overwrite.c)			src/linksamp/overwrite.c
리스트 6.3	シンボル作成のサンプルスクリプト(addr.lds)	src/linksamp/addr.lds
리스트 6.4	シンボル作成のサンプルプログラム(addr.c)	src/linksamp/addr.c
図6.6		addr の解析結果(抜粋)				src/linksamp/addr.od
図6.7		addr の実行結果					src/linksamp/addr.out
리스트 .5	シンボル衝突のサンプルスクリプト(conflict.lds)	src/linksamp/conflict.lds
リスト6.6	シンボル衝突のサンプルプログラム(conflict.c)	src/linksamp/conflict.c
図6.10		conflict の解析結果(抜粋)			src/linksamp/conflict.od
図6.11		conflict の実行結果				src/linksamp/conflict.out
리스트 .7	定義可能な初期値ありの領域			---
리스트 6.8	定義不可能な初期値ありの領域			---
리스트 6.9	変数作成のサンプルスクリプト(valiable.lds)	src/linksamp/valiable.lds
리스트 6.10	変数作成のサンプルプログラム(valiable.c)	src/linksamp/valiable.c
리스트 6.11	FILL()の利用方法				---
리스트 6.12	FILLEXPの利用方法				---
図6.13		valiable の解析結果(抜粋)			src/linksamp/valiable.od
図6.14		valiable の実行結果				src/linksamp/valiable.out
리스트 6.13	セクションの作成書式				---
리스트 6.14	セクションの記述				---
리스트 6.15	LMA指定のサンプルスクリプト(lma.lds)		src/linksamp/lma.lds
図6.16		lma の解析結果(抜粋)				src/linksamp/lma.od
図6.17		nm lma の結果					src/linksamp/lma.nm
--------------------------------------------------------------------------------
리스트 7.1	リンクの順番のサンプルプログラム(ordermain.c, ...)
								src/order/ordermain.c
								src/order/order1.c
								src/order/order2.c
리스트 7.2	重複シンボルのサンプルプログラム(dupmain.c, ...)
								src/duplicate/dupmain.c
								src/duplicate/duptest1.c
								src/duplicate/duptest2.c
								src/duplicate/dup1.c
								src/duplicate/dup2.c
리스트 7.3	バイナリデータの焼き込み(binary.c)		src/binary/binary.c
図7.21		nm binary の結果				src/binary/binary.nm
図7.22		objdump -h binary の結果			src/binary/binary.od
리스트 7.4	.incbin の利用(incbin.s)			src/binary/incbin.s
리스트 7.5	usr/initramfs_data.S 中のコメント		---
리스트 7.6	リンカスクリプト(bindata.scr)			src/binary/bindata.scr
--------------------------------------------------------------------------------
리스트 8.1	ELF形式のロード部分(imgact_elf.c)		---
図8.1		man execl より抜粋				---
図8.2		readelf -S /bin/ls の結果			src/loader/ls.shdr
図8.3		readelf -S /usr/bin/gcc の結果			src/loader/gcc.shdr
리스트 8.2	リンカスクリプトの修正				src/loader/ldscript.diff
図8.4		readelf -l /bin/ls の結果			src/loader/ls.phdr
리스트 8.3	フラグ変更用のプログラム(chflg.c)		src/loader/chflg.c
리스트 8.4	_start()の先頭部分(crt1.c)			---
리스트 8.5	(stack_sample.c)				src/stack/stack_sample.c
리스트 8.6	(stack_sample.s)				src/stack/stack_sample.s
리스트 8.7	簡易ローダ(loader.c)				src/loader/loader.c
리스트 8.8	ロード対象のサンプルプログラム(sample.c)	src/loader/sample.c
図8.7		簡易ローダの実行結果				src/loader/loader.out
--------------------------------------------------------------------------------
리스트 9.1	コアダンプ作成用プログラム(down.c)		src/core/down.c
図9.3		実行形式のセクション構成			src/core/down.readelf
図9.4		コアダンプの解析				src/core/core.readelf
리스트 9.2	elf_puthdr()					---
리스트 9.3	elf_putnote()					---
리스트 9.4	Elf_Note の定義(elf_common.h)			---
리스트 9.5	prstatus_t の定義(procfs.h)			---
리스트 9.6	struct reg の定義(reg.h)			---
리스트 9.7	struct fpreg の定義(reg.h)			---
리스트 9.8	prpsinfo_t の定義(procfs.h)			---
図9.5		コアダンプの解析				src/core/nm.out
図9.6		変数 count 付近のダンプ				---
리스트 9.9	実行再開用のプログラム(continue.c)		src/continue/continue.c
리스트 9.10	実行再開の実験用サンプルプログラム(calc.c)	src/continue/calc.c
図9.7		calc.c の実行結果				src/continue/calc.comp
								src/continue/calc.out
図9.10		実行の再開					src/continue/continue.out
리스트 9.A	_setjmp()/_longjmp() の利用例(setjmp.c)		src/setjmp/setjmp.c
図9.A		setjmp.c の実行結果				src/setjmp/setjmp.out
리스트 9.B	_setjmp()/_longjmp() のソース(_setjmp.S)	src/setjmp/_setjmp.S
리스트 9.C	_setjmp() 呼び出し後にスタックが破壊される例(setjmp2.c)
								src/setjmp/setjmp2.c
図9.B		setjmp2.c の実行結果				src/setjmp/setjmp2.out
--------------------------------------------------------------------------------
리스트 10.1	逆アセンブル用のサンプルプログラム(rasm.c)	src/rasm/rasm.c
리스트 10.2	逆アセンブル用のサンプルプログラム(rasm2.c)	src/rasm/rasm2.c
리스트 10.3	rasm.o の逆アセンブル結果			src/rasm/rasm.o.ra
리스트 10.4	rasm の逆アセンブル結果				src/rasm/rasm.ra
리스트 10.5	rasm.o のセクション，再配置テーブル，シンボルテーブル
								src/rasm/rasm.o.re
리스트 10.6	rasm2.o のシンボルテーブル			src/rasm/rasm2.o.re
리스트 10.7	rasm のシンボルテーブル				src/rasm/rasm.re
리스트 10.8	i386依存の定義(/usr/include/machine/elf.h)	---
리스트 10.9	weak シンボルの定義の例(weak.c)			src/weak/weak.c
리스트 10.10	グローバルシンボルの定義の例(global.c)		src/weak/global.c
리스트 10.11	weak シンボルの利用の例(main.c)			src/weak/main.c
리스트 10.12	global.o をリンクした場合の実行結果		src/weak/global.exec
리스트 10.13	global.o をリンクしなかった場合の実行結果	src/weak/noglobal.exec
리스트 10.14	実行形式 global のシンボルテーブル(抜粋)	src/weak/global.nm
리스트 10.15	実行形式 noglobal のシンボルテーブル(抜粋)	src/weak/noglobal.nm
리스트 10.16	ライブラリアーカイブを利用した場合の実行結果	src/weak/global_a.exec
리스트 10.17	man syscall					---
리스트 10.18	__syscall() の呼び出し				---
리스트 10.19	syscall()の定義(抜粋)				---
리스트 10.20	システムコール用ライブラリ(syscall.s)		src/linker/syscall.s
리스트 10.21	文字列表示用ライブラリ(service.c)		src/linker/service.c
리스트 10.22	スタートアップ(crt.c)				src/linker/crt.c
리스트 10.23	サンプルプログラム(main.c)			src/linker/main.c
리스트 10.24	サンプルプログラム(sample.c)			src/linker/sample.c
리스트 10.25	サンプルプログラム(sample2.c)			src/linker/sample2.c
리스트 10.26	サンプルプログラムの実行結果			src/linker/sample.exec
리스트 10.27	シンボル解決用ライブラリ(linklib.h)		src/linker/linklib.h
리스트 10.28	シンボル解決用ライブラリ(linklib.c)		src/linker/linklib.c
리스트 10.29	ダイナミックリンカ(dynlink.c)			src/linker/dynlink.c
리스트 10.30	ダイナミックリンカの実行結果			src/linker/dynlink.exec
리스트 10.31	実行形式用のリンカ(linker.c)			src/linker/linker.c
리스트 10.32	実行形式用リンカの実行結果			src/linker/linker.exec
리스트 10.33	リンカで作成した実行形式の実行結果		src/linker/sample2.exec
리스트 10.34	PowerPC用のシンボル解決				---
--------------------------------------------------------------------------------
리스트 11.1	라이브러리 사용 샘플 프로그램(sample.c)	src/shared/sample.c
리스트 11.2       라이브러리 사용 샘플 프로그램(main.c)	src/shared/main.c
그림 11.7		sample_shared 의 실행결과			src/shared/sample_shared.exec
그림 11.11		sample_static 의 실행결과			src/shared/sample_static.exec
그림 11.13		readelf -a sample_pic.o 의 출력결과		src/shared/sample_pic.o.re
리스트 11.3	i386の再配置種別(/usr/include/machine/elf.h 에서 발췌)
								---
그림 11.14		objdump -d sample_pic.o 의 출력결과		src/shared/sample_pic.o.ra
그림 11.15		readelf -a libsample.so.1 의 출력결과		src/shared/libsample.so.1.re
리스트 11.4	Elf32_Dyn 의 정의(elf32.h 에서 발췌)		---
리스트 11.5	d_tag 가 가진 값(elf_common.h 에서 발췌)		---
그림 11.16		libsample.so.1 의 .got 섹션 덤프 결과	src/shared/libsample.so.1.got
그림 11.17		objdump -d libsample.so.1의 출력결과		src/shared/libsample.so.1.ra
그림 11.18		readelf -a sample_shared의 출력결과		src/shared/sample_shared.re
그림 1.19		objdump -d sample_shared의 출력결과		src/shared/sample_shared.ra
그림 11.20		sample_shared .got 섹션의 덤프 결과	src/shared/sample_shared.got
리스트 11.6	.rtld_start의 정의(i386/rtld_start.S)		---
리스트 11.7	_rtld()의 정의(rtld.c)				---
리스트 11.8	init_rtld()의 정의(rtld.c)			---
리스트 11.9	digest_phdr()의 정의(rtld.c)			---
리스트 11.10	digest_dynamic()의 정의(rtld.c)			---
리스트 11.11	relocate_objects()의 정의(rtld.c)		---
리스트 11.12	init_pltgot()의 정의(i386/reloc.c)		---
리스트 11.13	_rtld_bind()의 정의(rtld.c)			---
리스트 11.14	dlopen()/dlsym()/dlclose()의 사용 예(dlopen.c)	src/shared/dlopen.c
그림 11.21		dlopen.c 의 실행결과				src/shared/dlopen.exec
리스트 11.15	dlopen()의 정의(rtld.c)				---
--------------------------------------------------------------------------------

以上
