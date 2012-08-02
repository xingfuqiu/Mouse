unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TForm1 = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    CheckBox1: TCheckBox;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

  function MR_StartRecord(hWnd: THandle; nOnlyKeyBorad: Integer): Integer; stdcall; external 'MouseRecrod.dll'
  function MR_StopRecord(): Integer; stdcall; external 'MouseRecrod.dll'
  function MR_StartPlayBack(hWnd: THandle; nDoClear: Integer): Integer; stdcall; external 'MouseRecrod.dll'
  function MR_StopPlayBack(): Integer; stdcall; external 'MouseRecrod.dll'

implementation

uses Math;

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
  MR_StartRecord(Handle, 0);
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  MR_StopRecord;
end;

procedure TForm1.Button3Click(Sender: TObject);
var
  bDoClear: Integer;
begin
  bDoClear := IfThen(CheckBox1.Checked, 1, 0);
  MR_StartPlayBack(Handle, bDoClear);
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  MR_StopPlayBack;
end;

end.
