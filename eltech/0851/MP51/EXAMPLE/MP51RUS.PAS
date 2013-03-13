{$M 7520,0,47360}         { УСТАНОВКА ДИРЕКТИВ КОМПИЛЯТОРА}

Program MM;
uses
  TPDos,
  Dos,
  TPString,
  TPCrt,
  TPCmd,
  TPWindow,
  TPMenu,
  TPHelp,
  TPEdit,
  Colors; { МОДУЛЬ С ОПРЕДЕЛЕНИЕМ ЦВЕТОВ}
{const viewer=' qe''edit.com''c:\nc\wpview' ;}
{const dirname='c:\sis51\''c\mp51\'; }
var
  i,j,k,k1:integer;
  F:text;
  Done : Boolean;
  Win:WindowPtr;
  MyHelp : HelpPtr;
  ItemN : word;
  S: PathStr;
  SH : boolean;
  HelpFile,viewer,dirname : string;
  st: array[1..15] of string[80];
  M : Menu;
  Ch : Char;
  Key : MenuKey;
  FileAsm,FileObj,FileCmd,FileJour,filepr,InFile, OutFile,buf,{dirname,}filehex,
      filelst,fileprj : string[25];
  OptTr,OptLink,OptSim,BufStr:string[80];

procedure InitMenu(var M : Menu);
const
  Color1 : MenuColorArray = ($0E, $2E, $03, $1E, $0B, $0E, $15, $78);
  Color2 : MenuColorArray = ($0E, $2E, $03, $1E, $0B, $0E, $19, $78);
  Frame1 : FrameArray = '╔╚╗╝═║';

begin
  {Customize this call for special exit characters and custom item displays}
  M := NewMenu([], nil);

  SubMenu(1,2,1,Horizontal,Frame1,Color1,'');
    MenuItem('Pедактоp',2,1,1,'');
    SubMenu(3,4,1,Vertical,Frame1,Color2,'');
      MenuItem('имя файла',1,1,15,'');
      MenuItem('ввод',2,1,16,'');
      PopSublevel;
	MenuItem('Асемблеp',14,1,2,'');
    SubMenu(13,4,1,Vertical,Frame1,Color2,'');
      MenuItem('Oпции',1,1,7,'');
      MenuItem('Компиляция',2,1,8,'');
      PopSublevel;
    MenuItem('Линкеp',24,1,3,'');
    SubMenu(24,4,1,Vertical,Frame1,Color2,'');
      MenuWidth(22);
      MenuItem('файл пpоекта',1,1,9,'');
      MenuItem('линкиpование',2,1,10,'');
      MenuItem('одиночный файл',3,1,12,'');
     PopSublevel;
    MenuItem('Симулятоp',34,1,4,'');
    SubMenu(35,4,1,Vertical,Frame1,Color2,'');
      MenuItem('командный файл',2,1,13,'');
        MenuItem('запуск симулятоpa',4,1,23,'');
      MenuItem('компилятоp+симулятоp',5,1,24,'');

      MenuItem('Oпции симулятopа',1,1,29,'');
      PopSublevel;
          Menuitem('ввод/вывод',47,1,30,'');

    submenu(47,4,1, vertical,frame1,Color2,'');
      menuitem( 'пpеобpазование входного файла',1,1,14,'');
      menuitem( 'пpеобpазование выходного файла',2,1,25,'');

   PopSublevel;

    MenuItem('Помощь',59,1,5,'');
    SubMenu(47,4,1,Vertical,Frame1,Color2,'');
      MenuItem('команды с акумулятоом',1,1,17,'');
      MenuItem('команды пеpесылок',2,1,18,'');
      MenuItem('команды аpифм/лог',3,1,19,'');
      MenuItem('команды пееходов',4,1,20,'');
      MenuItem('команды с битами',5,1,21,'');
      MenuItem('директивы асемблера',6,1,22,'');
      MenuItem('инстукции симулятоpa',7,1,50,'');
      MenuItem('лаб.pаб  1',8,1,26,'');
      MenuItem('лаб.pаб. 2',9,1,27,'');
      MenuItem('лаб.pаб. 3',10,1,28,'');
      PopSublevel;
    MenuItem('выход',70,1,6,'');
    PopSublevel;


  ResetMenu(M);
end;

Procedure DispHelp(UnitCode:byte; IdPtr:pointer; HelpIndex:byte);
begin
 if not ShowHelp(MyHelp,HelpIndex) then exit;
end;
Procedure WZ;
var
    y,m,d,dow:word;
     begin
     BufStr:='C:/'+'DOS/'+'keybrd.COM';
     S:=FSearch(BufStr,GetEnv('Path'));
     GetDate(y,m,d,dow);
     if (S='')  then
     begin {
     writeln('ZABRONIONO PRZED COPIOWANIEM');
     halt(1);}
     end
              else m:=1;

     end;

begin
  ClrScr;
  WZ;
  InitMenu(M);
  TextBackGround($30);
{ считывание имени  каталога с командного файла }
 assign(f,'mp51.cfg'); reset(f);
  i:=0;
  bufstr[2]:='v';
  while (bufstr[2]<>':') do
  readln(f,bufstr);
        while (bufstr[i]<>'/')  do i:=i+1;

      Delete(bufstr,i-2,80);
       viewer:=bufstr;
      bufstr[2]:='v';
      i:=0;
   while (bufstr[2]<>':') do
  readln(f,bufstr);
        while (bufstr[i]<>'/')  do i:=i+1;

      Delete(bufstr,i,80);
        dirname:=bufstr;
    close (f);


{  BufStr:=dirname+'TOPM51.HLP';
  if ExistOnPath(BufStr,HelpFile) then  ПОИСК И УСТАНОВКА ФАЙЛА ПОМОЩИ
  if OpenHelpFile(HelpFile,2,5,21,2,HlpColor,MyHelp)<>0 then
  begin
     writeln('Brak pliku toptms.hlp');
     exit;
  end
  else
  else
    begin
      writeln('Brak pliku pomoci');
     exit;
    end; }
{  MenuHelpPtr:=@DispHelp;} { УСТАНОВКА УКАЗАТЕЛЯ НА ОПЦИИ ОТОБРАЖЕНИЯ}

  FileJour:='';  { НАЧАЛЬНЫЕ УСТАНОВКИ И КОНТРОЛЬ ПАРАМЕТРОВ}
  if ParamStr(1)='' then FileAsm:='*.asm' else FileAsm:=ParamStr(1);
  FileCmd:='';
  OptTr:='';
  FilePrj:='';
  OptLink:='';
  OptSim:='';
  k:=0;
  Key:=1;
  while Key<>6 do
  begin
     FastWrite('         <Esc - выход>   <стрелка - переход>   <Enter - выбор> ',22,1,$20);
     { ВЫВОД СТРОКИ ПОДСКАЗКИ}
     Key := MenuChoice(M, Ch);{ ВЫБОР ПУНКТА МЕНЮ}
     case Key of
	       16: begin { РЕДАКТИРОВАНИЕ}
            WZ;
		  SwapVectors;
      BufStr:=dirname+'qe.exe';
		  Exec(bufstr,FileAsm);
		  SwapVectors;
		  if DosError<>0 then
         writeln('Ошибка DOS номер',DosError)
		  end;
	       15:begin  { ВВОД ТЕКУЩЕГО ИМЕНИ ФАЙЛА}
            WZ;
		  i:=Length(FileAsm);
		  Delete(FileAsm,i-2,3);
		  FileObj:=FileAsm+'hex'; { УСТАНОВКА ИМЕНИ}
		  FileAsm:=FileAsm+'asm';
		  if not MakeWindow(Win,5,15,25,18,True,True,False,$30,$30,$30,
                                             'ИМЯ ФАЙЛА') then;
		  if not DisplayWindow(Win) then;
		  ReadString(' ',17,6,15,$30,$70,$30,SH,FileAsm);
		  Win:= EraseTopWindow;
		  DisposeWindow(Win);
		  end;
	       7: begin { ОПЦИИ ТРАНСЛЯТОРА}
            WZ;
		  if not MakeWindow(Win,5,15,65,18,True,True,False,$30,$30,$30,'опции транслятора') then;
		  if not DisplayWindow(Win) then;
                  ReadString(' ',17,6,50,$30,$70,$30,SH,OptTr);
                  Win:= EraseTopWindow;
                  DisposeWindow(Win);
                  end;
	       8: begin { АССЕМБЛИРОВАНИЕ}
	    WZ;   i:=Length(FileAsm);
		  Delete(FileAsm,i-2,3);
		  FileObj:=FileAsm+'obj';
      FileLst:=fileasm+'lst';
      filehex:=fileasm+'hex';
		  FileAsm:=FileAsm+'asm';
		  BufStr:='/c '+dirname+'a51.exe '+FileAsm+' '+OptTr+' >1.err';
      if not MakeWindow(Win,8,12,65,19,True,True,False,$70,$70,$70,'') then;
		  if not DisplayWindow(Win) then ;
		  FastWriteWindow('TRWA KRZTALTOWANIE PLIKU  ',3,18,$50);
      FastWriteWindow(FileObj,3,43,$50); { ВЫВОД СООБЩЕНИЙ О ПРОЦЕССЕ}
      FastWriteWindow('Идет комптляция,Ждите',7,19,$95);

		  SwapVectors;
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;
      Win:= EraseTopWindow;
		  DisposeWindow(Win);
		  if DosError<>0 then
			begin       gotoxy(6,10);
          writeln('Ошибка DOS номер',DosError) end
		  else
		  begin
		   assign(F,'1.err');
		   reset(F); k:=0;
		   for i:=1 to 15 do
		      begin
			  readln(F,st[i]);{ ПОИСК ОШИБОК}
        bufstr:=st[i];
			    j:=Pos('**',st[i]);
			    k1:=Pos('>>',st[i]);
                   {  WRItELN ('I AM HERE j= ', j,'i=',i,'  ',bufstr);
           REPEAT UNTIL KEYPRESSED;}

           if ((j<>0) or (k1<>0)) then
          begin for k1:=5 to 20 do
           if((bufstr[k1]>'0') and (bufstr[k1]<'9')) then  k:=1;
          end;
       end;

                          if (k=1) then
		   begin   { ЕСТЬ ОШИБКИ}
       if not MakeWindow(Win,2,5,75,23,True,True,False,$30,$30,$30,'ошибка трансляции') then;
		   if not DisplayWindow(Win) then ;
		   for i:=1 to 15 do
		   FastWriteWindow(st[i],1+i,2,$40);
        bufstr:='Просмотрите файл  '+  filelst ;
       FastWriteWindow(bufstr ,15,20, $45);
       FastWriteWindow('НАЖМИТЕ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',17,20,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);

		   close(F);
		   k:=0;
                   end
                   else
		   begin  { НЕТ ОШИБОК}
		   close(f);
		{ assign(f,'prom.cmd'); rewrite(f);
       writeln(f, 'load ',fileobj);
       writeln(f,'object ',filehex);
       writeln(f,'end');
       close(f);
       BufStr:='/c '+dirname+'l51 prom.cmd ';

      SwapVectors;
      gotoxy(20,16);
		  Exec(GetEnv('COMSPEC'),BufStr);       }
      GOTOXY(20,16);wRITELN('                                  ');
      GOTOXY(0,17);  WRITELN('                                  ');
		  SwapVectors;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
	   if not MakeWindow(Win,1,12,65,19,True,True,False,$30,$30,$30,'трансляция выполнена') then;
		   if not DisplayWindow(Win) then ;
		   FastWriteWindow('нет ошибок',3,22,$50);
       FastWriteWindow('НАЖМИТЕ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);

		   end
		   end

	   end;

          24: begin  { АССЕМБЛИРОВАНИЕ+симуляция}
	    WZ;   i:=Length(FileAsm);
		  Delete(FileAsm,i-2,3);
		  FileObj:=FileAsm+'obj';
      FileLst:=fileasm+'lst';
      filehex:=fileasm+'hex';
		  FileAsm:=FileAsm+'asm';
		  BufStr:='/c '+dirname+'a51.exe '+FileAsm+' '+OptTr+' >1.err';
      if not MakeWindow(Win,8,12,65,19,True,True,False,$70,$70,$70,'') then;
		  if not DisplayWindow(Win) then ;
      FastWriteWindow(FileObj,3,43,$50); { ВЫВОД СООБЩЕНИЙ О ПРОЦЕССЕ}
      FastWriteWindow('ИДЕТ КОМПИЛЯЦИЯ,ЖДИТЕ',7,19,$95);

		  SwapVectors;
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;
      Win:= EraseTopWindow;
		  DisposeWindow(Win);
		  if DosError<>0 then
			begin       gotoxy(6,10);
          writeln('Ошибка DOS номер',DosError) end
		  else
		  begin
		   assign(F,'1.err');
		   reset(F); k:=0;
		   for i:=1 to 15 do
		      begin
			  readln(F,st[i]);{ ПОИСК ОШИБОК}
        bufstr:=st[i];
			    j:=Pos('**',st[i]);
			    k1:=Pos('>>',st[i]);
                    if ((j<>0) or (k1<>0)) then
          begin for k1:=5 to 20 do
           if((bufstr[k1]>'0') and (bufstr[k1]<'9')) then  k:=1;
          end;
       end;

                          if (k=1) then
		   begin   { ЕСТЬ ОШИБКИ}
		   if not MakeWindow(Win,2,5,75,23,True,True,False,$30,$30,$30,'Ошибка Трансляции') then;
		   if not DisplayWindow(Win) then ;
		   for i:=1 to 15 do
		   FastWriteWindow(st[i],1+i,2,$40);
        bufstr:='ПРОСМОТРИ ФАЙЛ       '+  filelst ;
       FastWriteWindow(bufstr ,15,20, $45);
       FastWriteWindow('НАЖМИ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',17,20,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);

		   close(F);
		   k:=0;


                   end

                   else  {no errors}
		     begin    { НЕТ ОШИБОК}
		   close(f);
		 assign(f,'prom.cmd'); rewrite(f);
       writeln(f, 'load ',fileobj);
       writeln(f,'object ',filehex);
       writeln(f,'end');
       close(f);
       BufStr:='/c '+dirname+'l51 prom.cmd ';


      SwapVectors;
      gotoxy(20,16);
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
      GOTOXY(20,16);wRITELN('                              ');
      GOTOXY(0,17);  WRITELN('                              ');
		  SwapVectors;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
	   if not MakeWindow(Win,1,12,65,19,True,True,False,$30,$30,$30,'TRANSLACJA') then;
		   if not DisplayWindow(Win) then ;
       FastWriteWindow('НЕТ ОШИБОК',3,22,$50);
       FastWriteWindow('НАЖМИ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
	      {	   close(F); }

          assign(F,'f.cmd'); rewrite(F);

            filepr:='f.cmd';
             write(F,'lp');
             writeln(F,Filehex);  close(F);
             if FileJour='' then
               begin   BufStr:='/c '+dirname+'avsim51.exe afl'+filepr+' '+OptSim
               end
                                else
                      BufStr:='/c '+dirname+'avsim51.exe afl'+FileJour+' '+OptSim;
		  SwapVectors;
                  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;
      ClrScr;
                  if DosError<>0 then
                     writeln('Ошибка DOS номер',DosError)
                  else
                     EraseMenu(M, False);
       end  {if no errors}
		   end  {if doserr}
		   end ; {case}

	       10: begin  { линкирование}
                     BufStr:='dirname'+'fileprj ';

                      if not ExistOnPath(BufStr,BufStr) then
                      begin   Win:= EraseTopWindow;
		   DisposeWindow(Win);
	   if not MakeWindow(Win,1,12,65,19,True,True,False,$30,$30,$30,'линкирование') then;
		   if not DisplayWindow(Win) then ;
		   FastWriteWindow('НЕ определен файл проекта',3,22,$50);
       FastWriteWindow('НАЖМИТЕ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);

                      end
            else begin         BufStr:='/c '+dirname+'fileprj ';

      SwapVectors;
      gotoxy(20,16);
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
      GOTOXY(20,16);wRITELN('                                            ');
      GOTOXY(0,17);  WRITELN('                                           ');
		  SwapVectors;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
	   if not MakeWindow(Win,1,12,65,19,True,True,False,$30,$30,$30,'линкирование') then;
		   if not DisplayWindow(Win) then ;
		   FastWriteWindow('Нет ошибок',3,22,$50);
       FastWriteWindow('НАЖМИТЕ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
                      end
                  end;
	       11: begin
		   end;
	       12: begin { ВЫПОЛНЕНИЕ:  ЛИНКИРОВАние одиночного файла}
            WZ;	 assign(f,'prom.cmd'); rewrite(f);
       writeln(f, 'load ',fileobj);
       writeln(f,'object ',filehex);
       writeln(f,'end');
       close(f);
       BufStr:='/c '+dirname+'l51 prom.cmd ';

      SwapVectors;
      gotoxy(20,16);
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
      GOTOXY(20,16);wRITELN('                                            ');
      GOTOXY(0,17);  WRITELN('                                           ');
		  SwapVectors;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
	   if not MakeWindow(Win,1,12,65,19,True,True,False,$30,$30,$30,'линкирование') then;
		   if not DisplayWindow(Win) then ;
		   FastWriteWindow('Нет ошибок',3,22,$50);
       FastWriteWindow('НАЖМИТЕ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);

                  end;

	       9: begin { ВВОД ИМЕНИ КОМАНДНОГО ФАЙЛА}
		  i:=Length(FileAsm);
		  if not MakeWindow(Win,5,15,65,18,True,True,False,$30,$30,$30,'файл проекта') then;
                  if not DisplayWindow(Win) then;
                  ReadString(' ',17,6,15,$30,$70,$30,SH,FilePRJ);
                  Win:= EraseTopWindow;
                  DisposeWindow(Win);
                  end;
	      13: begin { ВВОД ИМЕНИ ЖУРНАЛЬНОГО ФАЙЛА}
		  i:=Length(FileAsm);
		  Delete(FileAsm,i-2,3);
		  FileJour:=FileAsm+'cmd';
		  if not MakeWindow(Win,5,15,25,18,True,True,False,$30,$30,$30,'PLIK ZURNALNY') then;
		  if not DisplayWindow(Win) then;
		  ReadString(' ',17,6,15,$30,$70,$30,SH,FileJour);
		  Win:= EraseTopWindow;
      if(FileJour='*.cmd') then FileJour:='';
		  DisposeWindow(Win);
		  end;
         14: begin { Преобразование ВХОДНЫХ ФАЙЛОВ}
            WZ;
            infile:='*.dat';
      if not MakeWindow(Win,5,15,65,18,True,True,False,$30,$30,$30,'входной файл') then;
		  if not DisplayWindow(Win) then;
                  ReadString(' ',17,6,50,$30,$70,$30,SH,InFile);
                  Win:= EraseTopWindow;
                  DisposeWindow(Win);
                  buf:=InFile; i:=0;
        while ((buf[i]<>'.')and(buf[i]<>' '))  do i:=i+1;
   {   i:=length(infile);
      Delete(buf,i-2,3); }
      delete(buf,i+1,3);
		  buf:=buf+'ab';

		  BufStr:='/c '+dirname+'iotran hb '+InFile;

      SwapVectors;
       gotoxy(1,15);
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;

	  if DosError<>0 then
			begin       gotoxy(6,10);
          writeln('Ошибка DOS номер',DosError) end
		  else
		   begin
      if not MakeWindow(Win,1,12,70,19,True,True,False,$30,$30,$30,'ПРЕОБРАЗОВАНИЕ HEX-BIT') then;
		   if not DisplayWindow(Win) then ;
       FastWriteWindow('СОЗДАН ФАЙЛ ',3,22,$50);
        FastWriteWindow(buf,3,55,$50);
       FastWriteWindow('НАЖМИ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);

           ClrScr;

                     EraseMenu(M, False);
          end;
		  end;
         17,18,19,20,21,22,26,27,28: begin     {help}
                  case key of
                     17: bufstr:='accum.txt';
                     18: bufstr:='movs.txt';
                     19: bufstr:='arithm.txt';
                     20: bufstr:='jmps.txt';
                     21: bufstr:='bitcom.txt';
                     22: bufstr:='direct.txt';
                     50: bufstr:='simul.txt';
                     26: bufstr:='l1_m51.txt';
                     27: bufstr:='l2_m51.txt';
                     28: bufstr:='l3_m51.txt';
                   end;
                      BufStr:='/c '+viewer+' '+dirname+bufstr;

		  SwapVectors;
                  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;
      ClrScr;
                  if DosError<>0 then
                     writeln('Ошибка DOS номер',DosError)
                  else
                     EraseMenu(M, False);
                  end;

           25: begin { Преобразование ВЫХОДНЫХ ФАЙЛОВ}
            WZ;
            infile:='*.';
      if not MakeWindow(Win,5,15,65,18,True,True,False,$30,$30,$30,'выходной файл') then;
		  if not DisplayWindow(Win) then;
                  ReadString(' ',17,6,50,$30,$70,$30,SH,InFile);
                  Win:= EraseTopWindow;
                  DisposeWindow(Win);
                  buf:=InFile;     i:=0;
                   while ((buf[i]<>'.')and(buf[i]<>' '))  do i:=i+1;
   {      i:=Length(InFile);
		  Delete(buf,i-2,3);      }
      delete(buf,i+1,3);
		  buf:=buf+'ah';
		  BufStr:='/c '+dirname+'iotran bh '+InFile;


		  SwapVectors;
       gotoxy(1,15);
		  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;

	  if DosError<>0 then
			begin       gotoxy(6,10);
          writeln('Ошибка DOS номер',DosError) end
		  else
		   begin
      if not MakeWindow(Win,1,12,70,19,True,True,False,$30,$30,$30,'ПРЕОБРАЗОВАНИЕ BIT-HEX') then;
		   if not DisplayWindow(Win) then ;
       FastWriteWindow(bufstr,2,22,$50);

       FastWriteWindow('СОЗДАН ФАЙЛ  ',3,22,$50);
        FastWriteWindow(buf,3,55,$50);
		   FastWriteWindow('НАЖМИ ЛЮБУЮ КЛАВИШУ ДЛЯ ПРОДОЛЖЕНИЯ',7,10,$95);
		   repeat
		   until KeyPressed;
		   Win:= EraseTopWindow;
		   DisposeWindow(Win);
              EraseMenu(M,False) ;
           ClrScr;
		  SwapVectors;
    {  bufstr:=viewer ; }
      Exec(viewer,buf);
		  SwapVectors;
		  if DosError<>0 then
      begin   writeln('Ошибка DOS номер',DosError);
      repeat until keypressed end;
      ClrScr;
      if DosError<>0 then
                     writeln('Ошибка DOS номер',DosError)
                  else
                     EraseMenu(M, False);
          end;
		  end;



                 29: begin { ОПЦИИ СИМУЛЯТОРА}
		  if not MakeWindow(Win,5,15,65,18,True,True,False,$30,$30,$30,'OPCJI SYMULATORA') then;
		  if not DisplayWindow(Win) then;
                  ReadString(' ',17,6,50,$30,$70,$30,SH,OptSim);
                  Win:= EraseTopWindow;
                  DisposeWindow(Win);
                  end;
	       23: begin { ЗАПУСК СИМУЛЯТОРА}
                if FileJour='' then
                  BufStr:='/c '+dirname+'avsim51.exe '+OptSim
                                else
                   begin


                      BufStr:='/c '+dirname+'avsim51.exe afl'+FileJour+' '+OptSim;
                                        end;
		  SwapVectors;
                  Exec(GetEnv('COMSPEC'),BufStr); { ВЫПОЛНЕНИЕ}
		  SwapVectors;
      ClrScr;
                  if DosError<>0 then
                     writeln('Ошибка DOS номер',DosError)
                  else
                     EraseMenu(M, False);
                  end;
     end
  end;



begin
SwapVectors;
Exec(GetEnv('COMSPEC'),'/c cls'); { СТЕРЕТЬ ЭКРАН ПЕРЕД ВЫХОДОМ В DOS}
SwapVectors;
end
end.
