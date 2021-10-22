object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Mouse Maze'
  ClientHeight = 507
  ClientWidth = 768
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 185
    Top = 0
    Height = 507
    ExplicitLeft = 184
    ExplicitTop = 256
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 507
    Align = alLeft
    TabOrder = 0
    object Button2: TButton
      Left = 1
      Top = 1
      Width = 183
      Height = 25
      Align = alTop
      Caption = 'Find Exit'
      TabOrder = 0
      OnClick = Button2Click
    end
    object Edit1: TEdit
      Left = 1
      Top = 43
      Width = 183
      Height = 21
      Align = alTop
      Alignment = taCenter
      TabOrder = 1
      Text = '0'
    end
    object StaticText1: TStaticText
      Left = 1
      Top = 26
      Width = 183
      Height = 17
      Align = alTop
      Caption = 'delay(ms)'
      TabOrder = 2
    end
    object Button1: TButton
      Left = 1
      Top = 74
      Width = 75
      Height = 25
      Caption = 'Reset'
      TabOrder = 3
      OnClick = Button1Click
    end
    object CheckBox1: TCheckBox
      Left = 1
      Top = 105
      Width = 97
      Height = 17
      Caption = 'Number version'
      TabOrder = 4
      OnClick = CheckBox1Click
    end
    object StaticText2: TStaticText
      Left = 10
      Top = 128
      Width = 107
      Height = 17
      Caption = 'unknown:  0 or space'
      TabOrder = 5
    end
    object StaticText3: TStaticText
      Left = 10
      Top = 151
      Width = 59
      Height = 17
      Caption = 'wall: 1 or ='
      TabOrder = 6
    end
    object StaticText4: TStaticText
      Left = 10
      Top = 174
      Width = 66
      Height = 17
      Caption = 'check: 5 or x'
      TabOrder = 7
    end
    object StaticText5: TStaticText
      Left = 10
      Top = 197
      Width = 82
      Height = 17
      Caption = 'dead end: 4 or -'
      TabOrder = 8
    end
  end
  object Memo1: TMemo
    Left = 188
    Top = 0
    Width = 580
    Height = 507
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Consolas'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
end
