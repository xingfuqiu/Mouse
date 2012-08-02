object Form1: TForm1
  Left = 740
  Top = 286
  Width = 233
  Height = 294
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 200
    Height = 35
    Caption = 'startrecord'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 64
    Width = 200
    Height = 35
    Caption = 'stoprecord'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 160
    Width = 200
    Height = 35
    Caption = 'startplayback'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 216
    Width = 200
    Height = 35
    Caption = 'stopplay'
    TabOrder = 3
    OnClick = Button4Click
  end
  object CheckBox1: TCheckBox
    Left = 112
    Top = 136
    Width = 97
    Height = 17
    Caption = 'CheckBox1'
    TabOrder = 4
  end
end
