#include "ftxui/dom/node.hpp"
#include "ftxui/dom/elements.hpp"

namespace ftxui {

using namespace ftxui;

static const std::vector<std::vector<std::vector<std::wstring>>> elements = {
  {
    {L"Replaced by the gauge"},
  },
  {
    {L".  "},
    {L".. "},
    {L"..."},
  },
  {
    {L"|"},
    {L"/"},
    {L"-"},
    {L"\\"},
  },
  {
    {L"+"},
    {L"x"},
  },
  {
    {L"|  "},
    {L"|| "},
    {L"|||"},
  },
  {
    {L"←"},
    {L"↖"},
    {L"↑"},
    {L"↗"},
    {L"→"},
    {L"↘"},
    {L"↓"},
    {L"↙"},
  },
  {
    {L"▁"},
    {L"▂"},
    {L"▃"},
    {L"▄"},
    {L"▅"},
    {L"▆"},
    {L"▇"},
    {L"█"},
    {L"▇"},
    {L"▆"},
    {L"▅"},
    {L"▄"},
    {L"▃"},
    {L"▁"},
  },
  {
    {L"▉"},
    {L"▊"},
    {L"▋"},
    {L"▌"},
    {L"▍"},
    {L"▎"},
    {L"▏"},
    {L"▎"},
    {L"▍"},
    {L"▌"},
    {L"▋"},
    {L"▊"},
  },
  {
    {L"▖"},
    {L"▘"},
    {L"▝"},
    {L"▗"},
  },
  {
    {L"◢"},
    {L"◣"},
    {L"◤"},
    {L"◥"},
  },
  {
    {L"◰"},
    {L"◳"},
    {L"◲"},
    {L"◱"},
  },
  {
    {L"◴"},
    {L"◷"},
    {L"◶"},
    {L"◵"},
  },
  {
    {L"◐"},
    {L"◓"},
    {L"◑"},
    {L"◒"},
  },
  {
    {L"◡"},
    {L"⊙"},
    {L"◠"},
  },
  {
    {L"⠁"},
    {L"⠂"},
    {L"⠄"},
    {L"⡀"},
    {L"⢀"},
    {L"⠠"},
    {L"⠐"},
    {L"⠈"},
  },
  {
    {L"⠋"},
    {L"⠙"},
    {L"⠹"},
    {L"⠸"},
    {L"⠼"},
    {L"⠴"},
    {L"⠦"},
    {L"⠧"},
    {L"⠇"},
    {L"⠏"},
  },
  {
    {L"(*----------)"},
    {L"(-*---------)"},
    {L"(--*--------)"},
    {L"(---*-------)"},
    {L"(----*------)"},
    {L"(-----*-----)"},
    {L"(------*----)"},
    {L"(-------*---)"},
    {L"(--------*--)"},
    {L"(---------*-)"},
    {L"(----------*)"},
    {L"(---------*-)"},
    {L"(--------*--)"},
    {L"(-------*---)"},
    {L"(------*----)"},
    {L"(-----*-----)"},
    {L"(----*------)"},
    {L"(---*-------)"},
    {L"(--*--------)"},
    {L"(-*---------)"},
  },
  {
    {L"[      ]"},
    {L"[=     ]"},
    {L"[==    ]"},
    {L"[===   ]"},
    {L"[====  ]"},
    {L"[===== ]"},
    {L"[======]"},
    {L"[===== ]"},
    {L"[====  ]"},
    {L"[===   ]"},
    {L"[==    ]"},
    {L"[=     ]"},
  },
  {
    {L"[      ]"},
    {L"[=     ]"},
    {L"[==    ]"},
    {L"[===   ]"},
    {L"[====  ]"},
    {L"[===== ]"},
    {L"[======]"},
    {L"[ =====]"},
    {L"[  ====]"},
    {L"[   ===]"},
    {L"[    ==]"},
    {L"[     =]"},
  },
  {
    {L"[==    ]"},
    {L"[==    ]"},
    {L"[==    ]"},
    {L"[==    ]"},
    {L"[==    ]"},
    {L" [==   ]"},
    {L"[  ==  ]"},
    {L"[   == ]"},
    {L"[    ==]"},
    {L"[    ==]"},
    {L"[    ==]"},
    {L"[    ==]"},
    {L"[    ==]"},
    {L"[   ==] "},
    {L"[  ==  ]"},
    {L"[ ==   ]"},
  },
  {
    {
      L" ─╮",
      L"  │",
      L"   ",
    },
    {
      L"  ╮",
      L"  │",
      L"  ╯",
    },
    {
      L"   ",
      L"  │",
      L" ─╯",
    },
    {
      L"   ",
      L"   ",
      L"╰─╯",
    },
    {
      L"   ",
      L"│  ",
      L"╰─ ",
    },
    {
      L"╭  ",
      L"│  ",
      L"╰  ",
    },
    {
      L"╭─ ",
      L"│  ",
      L"   ",
    },
    {
      L"╭─╮",
      L"   ",
      L"   ",
    }
  },
  {
    {
      L"   /\\O  ",
      L"    /\\/ ",
      L"   /\\   ",
      L"  /  \\  ",
      L"LOL  LOL",
    },
    {
      L"    _O  ",
      L"   //|_ ",
      L"    |   ",
      L"   /|   ",
      L"   LLOL ",
    },
    {
      L"     O  ",
      L"    /_  ",
      L"    |\\  ",
      L"   / |  ",
      L" LOLLOL ",
    }
  }
};

std::unique_ptr<Node> spinner(int c, size_t index) {
  if (c == 0) {
    index %= 40;
    if (index > 20)
      index = 40-index;
    return gauge(index * 0.05);
  }
  c %= elements.size();
  index %= elements[c].size();
  std::vector<Element> lines;
  for(const auto& it : elements[c][index])
    lines.push_back(text(it));
  return vbox(std::move(lines));
}

};  // namespace ftxui
