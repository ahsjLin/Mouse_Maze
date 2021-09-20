object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 507
  ClientWidth = 768
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
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
      ExplicitTop = 47
    end
  end
  object Memo1: TMemo
    Left = 185
    Top = 0
    Width = 583
    Height = 507
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Fixedsys'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
end
