object Main: TMain
  Left = 378
  Top = 182
  Width = 625
  Height = 538
  HorzScrollBar.Tracking = True
  VertScrollBar.Tracking = True
  Caption = 'ScreenSnapper'
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Arial'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  PixelsPerInch = 96
  TextHeight = 18
  object Status: TStatusBar
    Left = 0
    Top = 493
    Width = 617
    Height = 19
    Panels = <
      item
        Bevel = pbNone
        Width = 50
      end>
    SimplePanel = False
  end
  object Pages: TPageControl
    Left = 0
    Top = 0
    Width = 617
    Height = 493
    ActivePage = AllSheet
    Align = alClient
    TabOrder = 1
    object MainSheet: TTabSheet
      Caption = 'Last snap'
      OnShow = MainSheetShow
      object Img: TImage
        Left = 8
        Top = 40
        Width = 105
        Height = 17
        Hint = 'Last taken screenshot, click to enlarge'
        AutoSize = True
        OnClick = ImgClick
        OnDblClick = ImgDblClick
      end
      object NameLab: TLabel
        Left = 8
        Top = 16
        Width = 80
        Height = 18
        Caption = 'Last saved:'
        Visible = False
      end
      object IntroMemo: TMemo
        Left = 8
        Top = 18
        Width = 592
        Height = 420
        Anchors = [akLeft, akTop, akRight, akBottom]
        Lines.Strings = (
          'Welcome to Snapper, version Feb 25, 2010'
          ''
          'Snapper enables you to make screenshots easily.'
          ''
          'To make a screenshot, press '#39'PrtSc'#39' (the PrintScreen key).'
          'The screenshot will be saved automatically in a JPG file.'
          ''
          'On the '#39'All snaps'#39' page you will see an overview of '
          'all the screenshots in the folder you chose for storing your'
          'screenshots.  This will default to the folder where you'
          'placed this program in. '
          ''
          'If you close Snapper, it will put itself in the tray.'
          'Use the '#39'Unload Snapper'#39' button or popup menu item'
          'to remove it from memory.'
          ''
          'Snapper'#39's homepage is at at http://www.ovosoft.net/snapper.'
          ''
          'Please mail questions and suggestions to'
          'Michiel Overtoom'
          'motoom@xs4all.nl')
        ReadOnly = True
        TabOrder = 0
      end
    end
    object SettingsSheet: TTabSheet
      Caption = 'Settings'
      ImageIndex = 2
      OnShow = SettingsSheetShow
      object Label4: TLabel
        Left = 17
        Top = 309
        Width = 84
        Height = 18
        Caption = 'Overlay text:'
      end
      object Label5: TLabel
        Left = 16
        Top = 143
        Width = 162
        Height = 18
        Caption = 'Screenshot JPG quality'
      end
      object JpgQualityLab: TLabel
        Left = 382
        Top = 143
        Width = 27
        Height = 18
        Caption = '000'
      end
      object Label1: TLabel
        Left = 16
        Top = 64
        Width = 183
        Height = 18
        Caption = 'Save screenshots in folder'
      end
      object Label2: TLabel
        Left = 16
        Top = 104
        Width = 219
        Height = 18
        Caption = 'Start screenshot filenames with '
      end
      object Label3: TLabel
        Left = 17
        Top = 357
        Width = 301
        Height = 18
        Caption = 'Overlay text spacing from top of screenshot:'
      end
      object Label8: TLabel
        Left = 401
        Top = 357
        Width = 40
        Height = 18
        Caption = 'pixels'
      end
      object Label9: TLabel
        Left = 16
        Top = 24
        Width = 158
        Height = 18
        Caption = 'Take screenshots from'
      end
      object SoundsCheck: TCheckBox
        Left = 16
        Top = 210
        Width = 321
        Height = 17
        Caption = 'Camera sound when making screenshot'
        TabOrder = 3
      end
      object SaveHalfSizeCheck: TCheckBox
        Left = 16
        Top = 240
        Width = 345
        Height = 17
        Caption = 'Save screenshots half size'
        TabOrder = 4
      end
      object OverlayEdit: TEdit
        Left = 108
        Top = 305
        Width = 393
        Height = 26
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 5
        OnChange = OverlayEditChange
      end
      object OverlayFontButton: TButton
        Left = 519
        Top = 305
        Width = 75
        Height = 25
        Anchors = [akTop, akRight]
        Caption = 'Font...'
        TabOrder = 6
        Visible = False
      end
      object JpgQualityBar: TScrollBar
        Left = 192
        Top = 145
        Width = 177
        Height = 16
        LargeChange = 10
        Min = 25
        PageSize = 0
        Position = 90
        SmallChange = 10
        TabOrder = 1
        OnChange = JpgQualityBarChange
      end
      object FolderEdit: TEdit
        Left = 208
        Top = 61
        Width = 290
        Height = 26
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 11
        OnChange = FolderEditChange
        OnKeyPress = FolderEditKeyPress
      end
      object ChooseButton: TButton
        Left = 512
        Top = 61
        Width = 81
        Height = 25
        Anchors = [akTop, akRight]
        Caption = 'Choose...'
        TabOrder = 12
        OnClick = ChooseButtonClick
      end
      object ExitButton: TButton
        Left = 20
        Top = 421
        Width = 153
        Height = 25
        Anchors = [akLeft, akBottom]
        Caption = 'Unload Snapper'
        TabOrder = 8
        OnClick = ExitButtonClick
      end
      object PrefixEdit: TEdit
        Left = 240
        Top = 101
        Width = 121
        Height = 26
        TabOrder = 0
        OnKeyPress = PrefixEditKeyPress
      end
      object OkButton: TButton
        Left = 481
        Top = 419
        Width = 113
        Height = 25
        Anchors = [akTop, akRight]
        Caption = '&Ok'
        TabOrder = 9
        OnClick = OkButtonClick
      end
      object OverlayTopEdit: TEdit
        Left = 342
        Top = 354
        Width = 53
        Height = 26
        TabOrder = 7
      end
      object ClickShotCheck: TCheckBox
        Left = 16
        Top = 181
        Width = 353
        Height = 17
        Caption = 'Left mouse click on tray icon makes screenshot'
        TabOrder = 2
      end
      object MonitorCombo: TComboBox
        Left = 184
        Top = 21
        Width = 257
        Height = 26
        Style = csDropDownList
        ItemHeight = 18
        TabOrder = 10
        Items.Strings = (
          'Entire desktop')
      end
    end
    object AllSheet: TTabSheet
      Caption = 'All snaps'
      ImageIndex = 3
      OnResize = AllSheetResize
      OnShow = AllSheetShow
      object Splitter1: TSplitter
        Left = 263
        Top = 0
        Width = 8
        Height = 460
        Cursor = crHSplit
        Beveled = True
        ResizeStyle = rsUpdate
      end
      object PreviewImg: TImage
        Left = 271
        Top = 0
        Width = 338
        Height = 460
        Align = alClient
        Center = True
        Picture.Data = {
          0A544A504547496D616765CF310000FFD8FFE000104A46494600010201004800
          480000FFE1012E4578696600004D4D002A000000080007011200030000000100
          010000011A00050000000100000062011B0005000000010000006A0128000300
          0000010002000001310002000000140000007201320002000000140000008687
          690004000000010000009C000000C80000004800000001000000480000000141
          646F62652050686F746F73686F7020372E3000323031303A30323A3235203134
          3A31333A35360000000003A001000300000001FFFF0000A00200040000000100
          000140A003000400000001000001000000000000000006010300030000000100
          060000011A00050000000100000116011B0005000000010000011E0128000300
          0000010002000002010004000000010000012602020004000000010000000000
          00000000000048000000010000004800000001FFED059650686F746F73686F70
          20332E30003842494D0425000000000010000000000000000000000000000000
          003842494D03ED00000000001000480000000100010048000000010001384249
          4D042600000000000E000000000000000000003F8000003842494D040D000000
          0000040000001E3842494D04190000000000040000001E3842494D03F3000000
          000009000000000000000001003842494D040A00000000000100003842494D27
          1000000000000A000100000000000000023842494D03F5000000000048002F66
          660001006C66660006000000000001002F6666000100A1999A00060000000000
          01003200000001005A00000006000000000001003500000001002D0000000600
          00000000013842494D03F80000000000700000FFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFFFFFFFFFF03E800000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FFFFFFFFFF03E800000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
          FF03E800000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF03E800
          003842494D040800000000001000000001000002400000024000000000384249
          4D041E000000000004000000003842494D041A00000000033D00000006000000
          0000000000000001000000014000000004006E006F006E006500000001000000
          0000000000000000000000000000000001000000000000000000000140000001
          0000000000000000000000000000000000010000000000000000000000000000
          000000000010000000010000000000006E756C6C0000000200000006626F756E
          64734F626A6300000001000000000000526374310000000400000000546F7020
          6C6F6E6700000000000000004C6566746C6F6E67000000000000000042746F6D
          6C6F6E670000010000000000526768746C6F6E670000014000000006736C6963
          6573566C4C73000000014F626A6300000001000000000005736C696365000000
          1200000007736C69636549446C6F6E67000000000000000767726F757049446C
          6F6E6700000000000000066F726967696E656E756D0000000C45536C6963654F
          726967696E0000000D6175746F47656E6572617465640000000054797065656E
          756D0000000A45536C6963655479706500000000496D672000000006626F756E
          64734F626A6300000001000000000000526374310000000400000000546F7020
          6C6F6E6700000000000000004C6566746C6F6E67000000000000000042746F6D
          6C6F6E670000010000000000526768746C6F6E67000001400000000375726C54
          455854000000010000000000006E756C6C54455854000000010000000000004D
          7367655445585400000001000000000006616C74546167544558540000000100
          000000000E63656C6C54657874497348544D4C626F6F6C010000000863656C6C
          546578745445585400000001000000000009686F727A416C69676E656E756D00
          00000F45536C696365486F727A416C69676E0000000764656661756C74000000
          0976657274416C69676E656E756D0000000F45536C69636556657274416C6967
          6E0000000764656661756C740000000B6267436F6C6F7254797065656E756D00
          00001145536C6963654247436F6C6F7254797065000000004E6F6E6500000009
          746F704F75747365746C6F6E67000000000000000A6C6566744F75747365746C
          6F6E67000000000000000C626F74746F6D4F75747365746C6F6E670000000000
          00000B72696768744F75747365746C6F6E6700000000003842494D0411000000
          00000101003842494D0414000000000004000000043842494D04210000000000
          5500000001010000000F00410064006F00620065002000500068006F0074006F
          00730068006F00700000001300410064006F00620065002000500068006F0074
          006F00730068006F007000200037002E003000000001003842494D0406000000
          0000070004000100010100FFE11248687474703A2F2F6E732E61646F62652E63
          6F6D2F7861702F312E302F003C3F787061636B657420626567696E3D27EFBBBF
          272069643D2757354D304D7043656869487A7265537A4E54637A6B633964273F
          3E0A3C3F61646F62652D7861702D66696C74657273206573633D224352223F3E
          0A3C783A7861706D65746120786D6C6E733A783D2761646F62653A6E733A6D65
          74612F2720783A786170746B3D27584D5020746F6F6C6B697420322E382E322D
          33332C206672616D65776F726B20312E35273E0A3C7264663A52444620786D6C
          6E733A7264663D27687474703A2F2F7777772E77332E6F72672F313939392F30
          322F32322D7264662D73796E7461782D6E73232720786D6C6E733A69583D2768
          7474703A2F2F6E732E61646F62652E636F6D2F69582F312E302F273E0A0A203C
          7264663A4465736372697074696F6E2061626F75743D27757569643A37323034
          666361642D323230662D313164662D626137612D646331356331303064636432
          270A2020786D6C6E733A7861704D4D3D27687474703A2F2F6E732E61646F6265
          2E636F6D2F7861702F312E302F6D6D2F273E0A20203C7861704D4D3A446F6375
          6D656E7449443E61646F62653A646F6369643A70686F746F73686F703A373230
          34666361632D323230662D313164662D626137612D6463313563313030646364
          323C2F7861704D4D3A446F63756D656E7449443E0A203C2F7264663A44657363
          72697074696F6E3E0A0A3C2F7264663A5244463E0A3C2F783A7861706D657461
          3E0A202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020200A20202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020200A2020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020200A202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020200A20202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020202020202020202020202020200A2020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020202020202020202020202020202020200A
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020200A202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020200A20202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020200A2020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020202020200A202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020200A20202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020202020202020202020202020202020200A2020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20200A2020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020200A202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020200A20202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020202020200A2020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020202020202020200A202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020200A20202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          0A20202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020200A2020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020200A202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020200A20202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020202020202020200A2020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020202020202020202020200A202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020200A20
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020200A20202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020200A2020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020200A202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020200A20202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020202020202020202020200A2020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020202020202020202020202020200A202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          200A202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020200A20202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020200A2020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020200A202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020200A20202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          20202020202020202020202020202020202020202020202020200A2020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020202020202020202020202020202020202020202020202020202020200A
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          202020200A202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          2020202020202020200A20202020202020202020202020202020202020202020
          2020202020202020202020202020202020202020202020202020202020202020
          200A3C3F787061636B657420656E643D2777273F3EFFEE000E41646F62650064
          0000000001FFDB0084000604040405040605050609060506090B080606080B0C
          0A0A0B0A0A0C100C0C0C0C0C0C100C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
          0C0C0C0C0C0C0C0C0C0C010707070D0C0D18101018140E0E0E14140E0E0E0E14
          110C0C0C0C0C11110C0C0C0C0C0C110C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C0C
          0C0C0C0C0C0C0C0C0C0C0CFFC00011080100014003011100021101031101FFDD
          00040028FFC40087000100020301010100000000000000000000060703040502
          0108010101000000000000000000000000000000011000010401030203050405
          0709090000000200010304051112062207213213314142621452822308516171
          B475725383B315163691B1D133732474373892A2B24363349435171101000000
          00000000000000000000000000FFDA000C03010002110311003F00B551040404
          0404040404040404040404040404040404040404040404040404040404040404
          040404041FFFD0B5510404040404040404040404040404040404040404040404
          040404040404040404040404040404041FFFD1B5510404040404040404040404
          040404040404040404040404040404040404040404040404040404041FFFD2B5
          5104040404040404040404040404040404040404040404040404040404040404
          04040404040404041FFFD3B55104040404040404040404040404040404040404
          04040404040404040404040404040404040404041FFFD4B55104040404040404
          0404040404040404040404040404040404040404040404040404040404040404
          1FFFD5B551040404040404040404040404040404040404040404040404040404
          0404040404040404040404041FFFD6B551040404040404040404040404040404
          0404040404040404040404040404040404040404040404041FFFD7B551040404
          0404040404040404040404040404040404040404040404040404040404040404
          040404041FFFD0B5510404040404040404040404040404040404040404040404
          040404040404040404040404040404041FFFD1B5510404040404040404040404
          04040404040404040404040404041C4E63CBF13C4B0A598CA34A55024089DA01
          633DD23E8DE0EE3FE741D6A9663B5521B516BE9CF18CA1BBC1F69B3136BFE541
          95010101010101010101010107FFD2B551040404041C7E51CBB8F716C7C790CF
          5BFA3A72CAD5E397D3965D64212361DB10997940BC74DA823DC8FBD3DBDE3F93
          3C65DC83C97227DB602BC6733465AE8EC642DB7737C42CFB8504A7039FC3E7F1
          9164F11682DD19B5D9286ADE2DE0E242ECC424DEF126DC8399CB7B87C4389B03
          6732015E795B7455844A498875D35D80C44C3F316D141CAE35DE8EDEF21BE18F
          A591786ECA4C3043663287D427F63013B6C727F70EEDC482708082019AEFAF6D
          71374E94B922B33C44E32FD2C47280937B5BD466D85F708904B78EF23C3F23C4
          4396C44FF51467DCD1C8E240FA83B893389B09749368823FCABBBDC0B8CDC2A3
          92C8EEBE1FEB2AD70298C35FB7B5B603FCA45B9074B8773CE33CC2ACD630564A
          71AC423640E338C808D9DC59D89999F5D1FCAE4839163BD1DB88B07FDB4395F5
          6914E556361866694E601033118CC00DD80250223D367579B72090C3CA7047C6
          E2E4925A1AD879A00B2D667FC3668CD99C776BEF7D74DBF690442AF7FF00B616
          2FB546C91C4C45B46CCB04810BBFBB5276D45BE631114161C52C72C612C46D24
          52331018BB3890BB6ACECEDED674106E43DEDEDDE072278FB59079ADC2EE3385
          68CA668C99F471236E8DCDF10B16E14126E35CAB8FF25C7364309702E56D769B
          8EAC405A6BB4C0998C0BF51320D0B3DC6E15572193C7D9CA0416B0D1B4D91090
          25018C0B6EDEB2160322F50184232332DC838D84EF8F6E333948F1B5B2251D89
          8DA3AEF3C47104864FA30899368CE5F0EFD8826B90C851C7529AF5F9C2B53AE3
          BE69E52610116F7BBBA0AFDFF309DAE6B5E87F68CAE1AE9F52D5A6F4FF006F97
          7E9F7106B7E628C24ED84B203EA0766B10BFE967777641BB67BC3C0B8C63F1D8
          EC8DF73BE1560F5AB578CA528F5885FADC7A05FE5DDBFE5412FE35CA703C9B18
          392C25B1B751C9C088588484DBDA2604C2405E3F1320D6E57CEB8A714823973B
          900A8F2EBE8C3A14929E9ED718C188DDBE6D36A0E0607BE3DB8CD5E8E8C1912A
          F666260846D46710993F83331BB6CD5FE62141DFE65CCB01C5717F5998B9F461
          3B9435A4F4E4975976390B69189E9E5F8BA5055DD98EEFE11B0838FE519C966E
          4376F93423385898886568C221631038C077EBA0EE1114177A0202020202020F
          FFD3B5510404040414FF00E687FC018FFE2B0FEED61058F83E2584C4E0030B15
          58E4AAE1B6DFA82C6F60DDBF1249B76BEA1C85D45B90569D8087FB3B3BCF7010
          93FD062F2421541F5F0FC4B113BF8BBFB4208FFECA0C5D8FC754E5792CFF003E
          CBC436F213DF2AF49A66636AE00032680CEDE0EC12C71897C221F31209377C38
          962B2FC1B259192001C9E2E27B752EB36920FA5A110EE6F17120626DBF6BABE1
          41DDED9E6ECE6F8161327689CECCD5846790BDA6713BC646FF00CB70DC83ADC8
          A95BBFC7F274694BE8DCB552782B4DAE9B259232102D5BEC93B3A0A6BB53CEB8
          E708C6FF0073B96D13C065E2964F5ADCF0BFA565A43771239059FC045DA3637F
          C1F4C44BD44164730CD52E3BDBBCB6670230046158E6A725560F49E5B0EC2328
          ECE82EB3F535F8D0713B1FC3B198CE1D4B3524433E6F301F596F21236F95DA57
          7211632D499B6E9BBC7A8F7120B02BE3A856B13D9AF5A286C5ADBF532C602252
          386BB5CDD9BA9C773FB50521F964E338CB183C8672DC2162C476CAAD569598DA
          1668A3390819DB412977809179B6C681DF3CD6322E6BC638DE52397FBB55A36C
          8DEA5503579753300060671F06F4487C1FA465341BBC83BB5DAFCC71AB181970
          B906A6709455E26A40231169D051B31F4381750ED41CEE3FCBF378BFCB95EB3A
          C915EA521E3AA4A5A89884D2833133BF8B7A6131347F67602076E3B9BDB8E27C
          5EAD08F19902BD2C42793B415049E698DB53EB73D4A3177DB1FC883D76BF398C
          9BBCB94938E549E9603314DE492ACD17A223622DA4E420CEE2DD5EA6DFF6A483
          2E0B8EE3B33F987E4C5918DA7831F185A8EB1F8C653304200462FD25B37910EE
          F8D0777F31D83C7D8E0259428846F636785EBCE22CC6C321B4641B9BC76756ED
          3ED08A0FBDD2C2F24E59D9FC6BE304ECDF70A77ADD78F5739C3D0773116F88B7
          98C9B7CC5B3ED20DBE19DCFEDBF20A3071DB15E1C4DA61680B057A2108B7374F
          A61B9BD23F1F0102DB217F36830FE62C043B63280B6D11B559859BD8CCC4E825
          5C078B6230FC3E8D3820037B55E396FCA62C456259418A4395CB573DC4FEC2F2
          8F4A0807676A4587EE773BC1D26F4F1B1C812C3037943432DA23FA8464DBF745
          078ED7E3AA730EE072BE5B9A886E4942DFD162A09998C210022D1D85DB6EE101
          0DAFF68A42F31209AF76B886233FC272AF6ABC6F7295596CD1B3B59A48E4841C
          D998BDBB0F6EC3141A1DB2C83724ED2E3ACE5631B7621826848E7119357AE471
          01F56BD5E988EE2F36E41C1FCB76331D3F012B13D5865B01909B64C71891B6D0
          8DDB4276D7C1D05C280808080808083FFFD4B5510404040414FF00E687FC018F
          FE2B0FEED6105C0829FECA7F8FFB9DFC55BF79B88393C6F327D9FE4797C2720A
          D30F15C9597B589CA431B9C60E4DA6D2DBEFF4D800C47AC4A3F29467B906F73C
          EE8E3F9A6265E1FC0E39B2F92CBED867B03149143040E4CF211BCA205E2DD0E4
          E3B044BCC82D2E25808B8F71AC6E1632F51A84011148CDA319B36A65A7BB71B9
          120DACCE49B1787BD92288E76A35E5B2F047E736841CF60FCC5B746415767FBC
          DD98E41C7A68729BEEBC9196CC6CB56479D8C9BC1A3936BC51C9FA0C66E9FB48
          31F6C782E72EF656FF001ECD31D53CA14E78F8E76762863310789C81FA85BD70
          2976FD9241A7DBEEEBD0E1F8A8F87F3C8E7C464711BA186C1432491C90B3BB86
          9E93193E9E51311F4CC3696F4164F0DE7D82E5FF005D2617D692A51308DEDC91
          BC51C846CEEED1EED09F6B3756E11F32081FE57BFC0190FE2B37EED5D066EF16
          2F3789E4D80EE261EA15E7C2B14192AD1B3EFF00A62DDD4DA33BEDDB2CC045FF
          0097B84FCBB907403F30DDB13A4361AECFF504CCFF0040D5A679B73FC3AB0FA3
          BBFA541D5E518CB1CFFB6166BC754E85BC9D719EA56B2DB6409233696213D5BA
          37EC162FB226821FC0FBD781C360EBF1EE69EBE1735878C6A48D2C131B48110B
          081691899896C66DDB876979C4BA904EF86771313CC2D5D6C3D7B2F8EA621A64
          A68DE28A690DCB50898BC5F630F56EDBFC94109E11FF00503CD7FE123FF35741
          D8FCC27FCADC97FB5ADFD7820DF979BE338776F78D64F2714D2529A0A5565920
          16378B7D57269085DDBA350DAFFCA415C776798F6E79C61A3A1C6E03CBF2D9E5
          89A8495EACB1CD1E84DBD8CCC01CC3D3DC3B1B78EEDA7F0EE4120EF5D6C855EC
          952AB913F572103508AE49AEEDD30030C85AFBF53674168F1EFF00E8319FF090
          7F56282AFEDBFF00CEBE7BF73FF1320E655C8D8ED2F3CCD965AA4C7C3F914DF5
          35AFC00E6304AE445B099B4D36EF2021F3908C661B907479AF78B0DC8B0D638C
          F0719F359BCCC45507D28658C228E56D92193CA20FE00FE6F2079C8C76A09DF0
          8E22FC7382D2E3BBC4A786B98CF23795E699C8E476F7ED633761F950557D8FE7
          980E2B8BB1C43909CB8FCE8E48822AC71485BCE5F4E361D405C41F78FC7B47E2
          DC82FA40404040404041FFD5B551040404040404041E268619E228A68C6588DB
          438CD9885DBF5B3F820F156953A80E15608EB83BEAE3100833BFEC1664199010
          6B0E2F1A367EA86A42D65DF579DA30DFAFE9DDA6E41B2830DAA34AD8B0DBAF1D
          8117D4465013667FD5B99D0648E28E28C638804231F0101666666FD4CC83D202
          0D68F178C8EC3D98EA42161DF579863063D5FE666D506CA0D7B58DC75B717B75
          61B0E3E02F2C627A7ECDCCE83380080B0833088F830B368CCC83EA020F860262
          E26CC425E0E2EDAB3B20C1571D8FA8E4F52AC55DCBCDE94621AFEDDACC836101
          010799238E4028E4163026D080999D9DBF43B3A0C556851A8C4352BC55D8BC49
          A2010677FD7B5990674180E8513B2368EBC45643C93B80BC8DFB09DB720CE808
          08080808083FFFD6B55104040404040404040404040404040404040404040404
          04040404040404040404040404040404041FFFD7B55104040404040404040411
          5E6FCFEA714B585AB2D492D4D9BB43520D84C021A900911BBEAFE1EA78330F57
          CA8254808082A5E3976E1FE63B955429E42AB1E2E228E073278C4B652F160D76
          B3F5120B690101010101010101010101045788F3FA9C9790723C457A9241FDDD
          B035659E4267F564739A327116F288BC1D3D5D5BBE1412A40404040404040404
          0404041FFFD0B5510404040404040404041F9EBBD9C5733072BE3F3C9C86D4F1
          E5F284D460367DB41CA48B4787ADFCBB9BEC79105C1C2B8AE678FC56C327C86D
          67CAC103C476D9D9E261676761D4CFCDAFFDD41108FB47CC3290FD5F23E71936
          C9C8DB9E1C79BC15A127F708368C4CDFA442240ECD726E46796E43C3B905C7C9
          5AC0CACD5F204EE47246E442FB89F572F6090EE7DFD7B7E141CDC35DA947F319
          CCEE5B9460AB5F0C12CF31BE8200115172277FD4C836B8DE5795F71F95966AAD
          CB588E078D328AA47019432DF905DB57371D0B63E9D5F607F083F13D5310DDEE
          0F29E4D92E614BB7DC4ECFD05DB117D4E5B2CCDB8ABC1E3D21FA0B4F1D7CDD71
          089075120E2F2AE0FCCF83E1A6E51C7F96E4B213E3D9A6BF4B2123CD14D133FE
          23ED7771E9D7775756DDDB64DC83BFCFF995BB7D919F94E1E7928DAB30539A39
          21271388A4B310480C4DA7B3538DD07238E711E6BCE78B6372B9CE4F7F151495
          211A34E81B83930C6C3F53664F34D25826F5B6FC225E6419FB47C879454E5D9F
          E03C8EE9E4EC6247EA295E95DCA428770375113B916F19A190771110750EE416
          D20AB72B9DCE71CEF6E3AB5CBB34BC6F9357786AD790DCA186D0B30E918BFB09
          CC63FF00E4A0927763959718E0993C8C327A774C3E9A8933E84D3CFD0243F346
          3BA5FE8D047331CAF3BC07B578B3BB2CB93E597F6410B592290BEAAC6B23B16A
          FA90C0DD0C2DE62D9F6D06B43DA1E6B728B64327CE3291725903D47682571A91
          48EDAFA6D1838EA02FE0FB360FC8833704CE725E6DC3F35C7323929315CA70D6
          9A95BCA5666F51BD395898D985E36DC7E94B09E9B7ED2080F6D783F21CA72BE6
          D4E9F2CBB8B9F1B7DA1B76E06773B87EB581F525EB1EAD6322F697FAC2457E8D
          AB09C356186491E638C040E62F31B8B33393FEB2F6A232A02020202020202020
          2020FFD1B55104040404040404040414FF007E89873DC0489F416CAEAEEFEC66
          F5204160770390D8E39C332D9AAC0C7669C0E500BB6ADEA1BB003BB7BC448B71
          20AF78676BEAF2EE374B9072DCDE47336B29134E75FEA4A3AD189EBF86201A69
          A3749E8E23F220E6F63EB612AF7379955C1B33626B8B455342291B6C72ED7763
          272726DCCFA16E41C5E5DC32DF2FEF3F35C453B4556D363209E16D748E538E3A
          5B6297FF004C9DFEE9881FC282C9ED0F3CA994C77F762F550C4F23C187A16B18
          C0D10B8C4FB3D4885BC34FE705BCA5F210A081F26E2F8EC9FE60AED0CCE42E62
          E1CBD384F1B3D394603390228C1A3DE43236C27866E9D3AA4D9F7825D37E5F38
          D4911C73720CF1C24CED201DC89C5C7DECECF069A20F1DD0E3D8FE3BD85C861B
          1D2C9352A8159A09662133213BF11EAE40202FE6F70A09B76F3FC01C67F8551F
          DD81057FC67FEA5F967F0A8BFABA282E0415DF7D38F58C970A2CA51D4729C7E5
          1C954907CCCD178CBA7EC0FC4FE8D0467259983B97CCF8662EBF562E9D61CFE6
          236F116934660849BE53FC37F96624193F3294D8B1FC6AF4E52C78EAD9078EE4
          B0F848032B0BEE17D1F436188F63EDF320E9D7EC4719B35E3B15F93E7A582616
          922942F4442404DA890BB43E2CEC8249C03B6D80E192E50F1572DDC9722717D6
          95C9239498E2DE4DE31C71BEE2F59C8B7EEF85043BB284DFFE81DCE1D7A9F2AC
          ECDEFD1ACDCFF4A0B81010101010101010101010107FFFD2B551040404040404
          040404119EE0700C4735C3063AF9C9049048D355B70E9BE3919B4F7F810933F5
          0A0D5E39DBE9A8E172589CF66EDF2483251B4327D6917444C242E21A9193396E
          EA3DDBBCA823547B0EF444E855E5B97878E99139E26293633893EA42E62FB742
          F8F48BA9049B8876C703C533B91CAE28E406C846117D1BEDF4A208F4DAC1A331
          7BBE22241B14380E36973EC97348EC4C57F27586ACB58B6FA2222D08EA3A36FD
          DFEEE3ED2F88906A729ED861F3BC82972286D58C4E72969B6F5270139187C05A
          4631312DADD3ECEA0E83DC0833F39EDB6039952AF1E51E48AF54F1AB92AEEC13
          03F83BFB9C5C5DDB5DAFF776A08C8F65325681AAE6B9BE67238CF61D2F55E363
          1FB264452EE1FBA8267CA78763B90F139F8C4D2495A8CC10C6C70BB3C8230481
          203339B17F36CDE283A384C54388C350C540652438FAD0D58A43D3710C31B462
          E5A68DB9D87C507168701C6D2E7D92E691D898AFE4EB0D596B16DF44445A11D4
          746DFBBFDDC7DA5F112093A0D3CD5CC7D1C3DEB991D3E82BC12496989B567884
          1DCD9D9FDBA8FB9055BF970E2E1478D5CE40713C52666676A806EE4435207710
          6D5F4F31B9FBBAB68120B3F3B82C567B15631595806CD1B43B6588B56F63EACE
          CEDE2242EDB8499057357B1D92C70BD4C3F37CC50C4EAFB2901BF4B3EBAB0909
          008FED18D04EB88712C7716C47F66D19679C4E53B13D8B47EA4D24B269B8CCB4
          66D5F6B7B19044B3DD998EDF27B3C8B059FBBC7AE5FF00FDF8D47E991DFCCFE0
          40EDBB4DCFAEF1DFD482C4AB07A15A181CCA5788043D437D4CB6B69B89FED3FB
          D0644040404040404040404041FFD3B551040404040404040404040404040404
          04040404040415FF002DED6E4794E6A79323C9EE071AB05119F1F80180358804
          74F577BF4918FA9B7D2F317DE413AA54EAD1A7053A910C156B46314108368200
          0DB445BF63320CC80808080808080808080808080808083FFFD4B55104040404
          0404040404040404040404040404040404040404040404040404040404040404
          0404041FFFD5B551040404040404040404040404040404040404040404040404
          0404040404040404040404040404041FFFD6B551040404040404040404040404
          0404040404040404040404040404040404040404040404040404041FFFD7B551
          0404040404040404040404040404040404040404040404040404040404040404
          040404040404041FFFD0B5510404040404040404040404040404040404040404
          040404040404040404040404040404040404041FFFD1B5510404040404040404
          040404040404040404040404040404040404040404040404040404040404041F
          FFD2B55104040404040404040404040404040404040404040404040404040404
          04040404040404040404041FFFD3B55104040404040404040404040404040404
          04040404040404040404040404040404040404040404041FFFD4B55104040404
          0404040404040404040404040404040404040404040404040404040404040404
          0404041FFFD5B551040404040404040404040404040404040404040404040404
          0404040404040404040404040404041FFFD6B551040404040404040404040404
          0404040404040404040404040404040404040404040404040404041FFFD9}
        OnDblClick = PreviewImgDblClick
      end
      object PreviewList: TListBox
        Left = 0
        Top = 0
        Width = 263
        Height = 460
        Align = alLeft
        ItemHeight = 18
        MultiSelect = True
        TabOrder = 0
        OnClick = PreviewListClick
        OnDblClick = PreviewListDblClick
        OnKeyDown = PreviewListKeyDown
      end
    end
  end
  object Systray: TSystray
    Hint = 'ScreenSnapper'
    PopupMenu = Popup
    OnLeftClick = SystrayLeftClick
    Left = 392
    Top = 8
  end
  object Popup: TPopupMenu
    Left = 336
    Top = 8
    object OpenPopupItem: TMenuItem
      Caption = '&Open'
      OnClick = OpenPopupItemClick
    end
    object SettingsPopupItem: TMenuItem
      Caption = '&Settings'
      OnClick = SettingsPopupItemClick
    end
    object UnloadPopupItem: TMenuItem
      Caption = '&Unload'
      OnClick = UnloadPopupItemClick
    end
  end
  object LoadTim: TTimer
    Enabled = False
    Interval = 100
    OnTimer = LoadTimTimer
    Left = 540
    Top = 157
  end
  object OverlayFontDlg: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Left = 458
    Top = 157
  end
end