{$M 7520,0,47360}         { ��������� �������� �����������}

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
  Colors; { ������ � ������������ ������}
{const viewer=' qe''edit.com'  'c:\nc\wpview' ;}
{const dirname='c:\sis51\''c:\mp51\';}
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
  Bufstr:string[80];
procedure InitMenu(var M : Menu);
const
  Color1 : MenuColorArray = ($2E, $0E, $03, $1E, $0B, $0E, $15, $78);
  Color2 : MenuColorArray = ($0E, $2E, $03, $1E, $0B, $0E, $19, $78);
  Frame1 : FrameArray = '�Ȼ�ͺ';

begin
  {Customize this call for special exit characters and custom item displays}
  M := NewMenu([], nil);

  SubMenu(1,2,1,Horizontal,Frame1,Color1,'');
    MenuItem('���⥪���',2,1,1,'');
    SubMenu(3,4,1,Vertical,Frame1,Color2,'');

      MenuItem('��騥 ᢥ�����',1,1,116,'');
      MenuItem('������ ������ ',1,1,117,'');
      MenuItem('������ ������',2,1,118,'');
      MenuItem('����७��� ������',3,1,119,'');
      MenuItem('ᯮᮡ� ����樨',4,1,120,'');
      MenuItem('������ ������',5,1,121,'');
      MenuItem('����� �����\�뢮��',6,1,122,'');
      MenuItem('���뢠���',7,1,123,'');
      MenuItem('⠩���',8,1,124,'');
      MenuItem('��᫥�. ����',9,1,125,'');

      PopSublevel;
	MenuItem('��⥬� ������ ',16,1,2,'');
    SubMenu(13,4,1,Vertical,Frame1,Color2,'');
      MenuItem('������� � �����⮮�',1,1,17,'');
      MenuItem('������� ��p��뫮�',2,1,18,'');
      MenuItem('������� �p��/�����',3,1,19,'');
      MenuItem('������� ��p�室��',4,1,20,'');
      MenuItem('������� � ��⠬�',5,1,21,'');
      PopSublevel;
     MenuItem('��४⨢�',34,1,130,'��४⨢� �ᥬ����');

      MenuItem('ᨬ����',45,1,3,'');
    SubMenu(24,4,1,Vertical,Frame1,Color2,'');

      MenuItem('��騥 ᢥ�����',1,1,9,'');
      MenuItem('����㧪�',2,1,10,'');
      MenuItem('����� ',3,1,12,'');
      menuitem( '�p���p�������� �室���� 䠩��',4,1,14,'');
      menuitem( '�p���p�������� ��室���� 䠩��',5,1,25,'');

     PopSublevel;
    MenuItem('�������� ',56,1,4,'');
    SubMenu(55,4,1,Vertical,Frame1,Color2,'');
     MenuItem('���.p��  1',1,1,26,'');
      MenuItem('���.p��. 2',2,1,27,'');
      MenuItem('���.p��. 3',3,1,28,'');

   PopSublevel;

    MenuItem('��室',70,1,6,'');
    PopSublevel;


  ResetMenu(M);
end;

Procedure DispHelp(UnitCode:byte; IdPtr:pointer; HelpIndex:byte);
begin
 if not ShowHelp(MyHelp,HelpIndex) then exit;
end;
{Procedure WZ;
var
    y,m,d,dow:word;
     begin
     BufStr:='C:/'+'DOS/'+'keybrd.COM';
     S:=FSearch(BufStr,GetEnv('Path'));
     GetDate(y,m,d,dow);
     if (S='')  then
     begin
     writeln('');
     halt(1);
     end
              else m:=1;

     end;
               }
begin
  ClrScr;
{  WZ; }
  InitMenu(M);
  TextBackGround($30);
{ ���뢠��� �����  ���� � ���������� 䠩�� }
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
  k:=0;
  Key:=1;
  while Key<>6 do
  begin
     FastWrite('         <Esc - ��室>   <��५�� - ���室>   <Enter - �롮�> ',22,1,$20);
     { ����� ������ ���������}
     Key := MenuChoice(M, Ch);{ ����� ������ ����}
             if key<>6 then
                    begin
                          bufstr:='not_ready.txt';

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
                     123:  bufstr:='int.txt';
                     124: bufstr:='taimer.txt';
                     125: bufstr:='ser_port.txt';
                     130:bufstr:='direct.txt';
                   end;
                      BufStr:='/c '+viewer+' '+dirname+bufstr;

		  SwapVectors;
                  Exec(GetEnv('COMSPEC'),BufStr); { ����������}
		  SwapVectors;
      ClrScr;
                  if DosError<>0 then
                     writeln('�訡�� DOS �����',DosError)
                  else
                     EraseMenu(M, False);

         end
  end;{ whyile key }

begin
SwapVectors;
Exec(GetEnv('COMSPEC'),'/c cls');
SwapVectors;
end
end.
